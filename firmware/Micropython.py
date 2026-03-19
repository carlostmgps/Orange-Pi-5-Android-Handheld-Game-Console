from machine import Pin, ADC
from time import sleep
import bluetooth
from ble_hid import BLE_HID, Gamepad

# GPIO Pin Definitions
GPIO_Y_AXIS = 4
GPIO_X_AXIS = 3
GPIO_TRIGGER_R = 2
GPIO_JOYSTICK_BTN = 5
GPIO_DPAD_W = 6
GPIO_DPAD_A = 7
GPIO_DPAD_D = 8
GPIO_DPAD_S = 9
GPIO_TRIGGER_L = 21
GPIO_LED_OUTPUT = 0

# Initialize Pins
x_axis = ADC(Pin(GPIO_X_AXIS))
y_axis = ADC(Pin(GPIO_Y_AXIS))
trigger_r = Pin(GPIO_TRIGGER_R, Pin.IN, Pin.PULL_UP)
joystick_btn = Pin(GPIO_JOYSTICK_BTN, Pin.IN, Pin.PULL_UP)
dpad_w = Pin(GPIO_DPAD_W, Pin.IN, Pin.PULL_UP)
dpad_a = Pin(GPIO_DPAD_A, Pin.IN, Pin.PULL_UP)
dpad_d = Pin(GPIO_DPAD_D, Pin.IN, Pin.PULL_UP)
dpad_s = Pin(GPIO_DPAD_S, Pin.IN, Pin.PULL_UP)
trigger_l = Pin(GPIO_TRIGGER_L, Pin.IN, Pin.PULL_UP)
led_output = Pin(GPIO_LED_OUTPUT, Pin.OUT)

# Initialize BLE HID Gamepad
ble = bluetooth.BLE()
hid = BLE_HID(ble)
gamepad = Gamepad(hid)

# Map analog values
def map_value(value, in_min, in_max, out_min, out_max):
    return int((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

# Main Loop
while True:
    if hid.is_connected():
        # Read analog joystick inputs
        x_value = map_value(x_axis.read_u16(), 0, 65535, -127, 127)
        y_value = map_value(y_axis.read_u16(), 0, 65535, -127, 127)

        # Read button states
        buttons = (
            (not joystick_btn.value()) << 0 |
            (not trigger_r.value()) << 1 |
            (not trigger_l.value()) << 2 |
            (not dpad_w.value()) << 3 |
            (not dpad_a.value()) << 4 |
            (not dpad_d.value()) << 5 |
            (not dpad_s.value()) << 6
        )

        # Send gamepad report
        gamepad.send_report(x_value, y_value, buttons)

        # Blink LED to indicate activity
        led_output.value(1)
        sleep(0.05)
        led_output.value(0)

    sleep(0.02)  # Run the loop at ~50Hz
