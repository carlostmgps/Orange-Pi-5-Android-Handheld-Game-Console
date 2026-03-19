#include <BleGamepad.h> // Include the BLE Gamepad library

// Define GPIO pins
#define GPIO_Y_AXIS      4
#define GPIO_X_AXIS      3
#define GPIO_TRIGGER_R   2
#define GPIO_MODE_BUTTON 1  // Currently unused
#define GPIO_LED_OUTPUT  0
#define GPIO_JOYSTICK_BTN 5
#define GPIO_DPAD_W      6
#define GPIO_DPAD_A      7
#define GPIO_DPAD_D      8
#define GPIO_DPAD_S      9
#define GPIO_TRIGGER_L   21

// Create a BLE Gamepad instance
BleGamepad bleGamepad("ESP32-C3 Gamepad", "My Company", 100); // Name, Manufacturer, Battery Level

void setup() {
  // Initialize BLE Gamepad
  bleGamepad.begin();

  // Set pin modes
  pinMode(GPIO_TRIGGER_R, INPUT_PULLUP);
  pinMode(GPIO_JOYSTICK_BTN, INPUT_PULLUP);
  pinMode(GPIO_DPAD_W, INPUT_PULLUP);
  pinMode(GPIO_DPAD_A, INPUT_PULLUP);
  pinMode(GPIO_DPAD_D, INPUT_PULLUP);
  pinMode(GPIO_DPAD_S, INPUT_PULLUP);
  pinMode(GPIO_TRIGGER_L, INPUT_PULLUP);
  pinMode(GPIO_Y_AXIS, INPUT); // Analog input
  pinMode(GPIO_X_AXIS, INPUT); // Analog input
  pinMode(GPIO_LED_OUTPUT, OUTPUT);

  digitalWrite(GPIO_LED_OUTPUT, LOW); // Turn off LED
}

void loop() {
  if (bleGamepad.isConnected()) {
    // Read analog joystick inputs
    int xValue = analogRead(GPIO_X_AXIS); // Read X axis
    int yValue = analogRead(GPIO_Y_AXIS); // Read Y axis

    // Map analog values to gamepad range (-127 to 127)
    int8_t xAxis = map(xValue, 0, 4095, -127, 127);
    int8_t yAxis = map(yValue, 0, 4095, -127, 127);

    // Read button states
    bool triggerR = !digitalRead(GPIO_TRIGGER_R);
    bool joystickBtn = !digitalRead(GPIO_JOYSTICK_BTN);
    bool dpadW = !digitalRead(GPIO_DPAD_W);
    bool dpadA = !digitalRead(GPIO_DPAD_A);
    bool dpadD = !digitalRead(GPIO_DPAD_D);
    bool dpadS = !digitalRead(GPIO_DPAD_S);
    bool triggerL = !digitalRead(GPIO_TRIGGER_L);

    // Send joystick and button states
    bleGamepad.setAxes(xAxis, yAxis, 0, 0, 0, 0); // X, Y, Z, Rx, Ry, Rz
    bleGamepad.press(1, joystickBtn);             // Button 1: Joystick button
    bleGamepad.press(2, triggerR);               // Button 2: R Trigger
    bleGamepad.press(3, triggerL);               // Button 3: L Trigger
    bleGamepad.setDpad(dpadW, dpadA, dpadD, dpadS); // D-Pad directions

    bleGamepad.sendReport(); // Send the report

    // Blink LED to indicate activity
    digitalWrite(GPIO_LED_OUTPUT, HIGH);
    delay(50);
    digitalWrite(GPIO_LED_OUTPUT, LOW);
  }

  delay(20); // Run the loop at ~50Hz
}
