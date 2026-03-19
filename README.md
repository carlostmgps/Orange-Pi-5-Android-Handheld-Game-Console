![3D Design](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/37f26c2ce783178d952240d1a9a3b437abac7435/image/Project.png)

# Orange-Pi-5-Handheld-Game-Console
Orange Pi 5 + Battery + Touch Screen + Microphone + Speaker + Fan + esp32 Custom PCB controller = AMAZING ANDROID AND LINUX GAME CONSOLE!!!!!!!

Hello I'm 12zcab,a secondary school student in HK.

# why I made this project?
Welp I'm a really big fan of retro gaming such as n64, gameboy, nes,gba(oh yah I loved Nintendo.) why? That's mainly because one day I found a few old books on a table near my home labeled "Free",and I took it home and read all of it.
Theres one that caused me to be a retro fan,an user manual of Hektor,a 8085 computer.After reading that book,I discovered Zilog80,an amazing and neat perfect and the easiest design I have ever seen.
You know what? Actually the Nintendo Gameboy's instruction set is really similar to Zilog80 and I started to research on how gameboy works and I even made my "own gameboy emulator" by searching how it works online and copy some of other's code then add more function myself.
Also I like to read code of the disassembled version of gameboy game Pokémon Red.
And now I really wanna make my own game console with orange pi that can emulate the Nintendo Game Console Series from NES to NDS.

# 3/7/2026 Day 1
 12:35pm
I just discovered the blueprint scheme a few days ago and now I realized,its the time to make my dream game console come true.
There are only 2 weeks left for me but I think i can make it in time.
So firstly my planned hardware should include:
1 Orange Pi 5 16gb ram    for games like MineCraft and emulators like RETROARCH
1 touchscreen
1 speaker ...or maybe 2?
1 Microphone
1 simple tiny fan to cool down my CM5
2 D1mini for my custom PCB comtroller
2 Joysticks
IDK A few buttons
Some Batteries

My goal:
1.Use linux to run minecraft Java
2.Use retroarch to emulate NDS Games

USB Battery Pack for Raspberry Pi - 10000mAh - 2 x 5V outputs  [LINK](https://www.adafruit.com/product/1566) 39.95USD
Orange Pi 5 16gb [Link](https://e.tb.cn/h.i2LfNGjXf5lZXff?tk=K51dUuX3cC2)  1900 rmb
2x 64gb tfcard [LINK](https://e.tb.cn/h.i2ybQZQlsHyMiE1?tk=S8PhUuRI9QB)  140rmb
7inch touchscreen [Link](https://e.tb.cn/h.i2RoroSwYrMQFAG?tk=mAtMUuRFne7) 198rmb
Cooling Fan 19rmb [LINK](https://e.tb.cn/h.idzK3fJlqxSjamQ?tk=dNAvUuRyINo)

Then I started designing my d1mini joycon😜😜(18:25pm)

Erm yah I just wired the power supply and watched some youtube and now is 23:58pm and I guess I gotta sleep.


# Day 2 8-3-2026  17:35
Humm I decided to use esp32 C3 supermini board I found in taobao as it's much smaller.
However...I really can't find a Kicad module so I use Conn_MMxNN to represent the board.
23:45 YEAH~~~~ I think this kinda good i guess
![KiCad 3D model](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/71797056b306445c05f4cd25ffa2676e7c43da14/image/d1minijoycon.png)

12:49am gotta sleep :/ I just finished routing the pcb😁😁
![KiCad Routed PCB](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/ca8e7b5abddabb205057067e1a284b8bcb0be144/image/Screenshot_20260309_004916_com.iiordanov.freebVNC_edit_134168961203485.jpg)
![KiCad Routed PCB](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/ca8e7b5abddabb205057067e1a284b8bcb0be144/image/Screenshot_20260309_004854_com.iiordanov.freebVNC_edit_134181280871712.jpg)

# Day 3 9-3-2026
Continued on pcb editing and searched for material needed in taobao website.

Also I hope I can finish the pcb design in 3 to 4days and prepare the material list in a week then start to design the case.
Hopefully I can submit the project for review before 23-3-2026.

# Day 6 12-3-2026
I just done a simple bom list and finished all the pcb designing(oh yeah it's name was d1mini joycon as I originally wanted to use d1mini but found out it only have 1 analog pin) (yay!) All files including the stl file can be found in the PCB-Design folder in github.
Erm because I'm lazy so I think i will just simply flip the board for another side hehe.
Also I just did some research on using esp32 to make controllers and I tried it with d1mini and it's perfect:D

# Day 11 17-3-2026
HUMMMMMMMM I hope this 3D model is okay I guess. Im not really good at designing.
![3D modelling](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/3c82e4e66f4b1be910bb6ef94337df1aa66ce39c/image/3D%20modeling.png)
The 3D model is uploaded to the Model file,but sadly i cant really share the original file cuz its made with tinkercad.
[LINK to TINKERCAD Project](https://www.tinkercad.com/things/lrAWRHE2oKm-orangepi-game-console?sharecode=MQfT5zH1kE5UchqxLdm9KHmoapcb7OkEz_jWbnckgjE)

# Day 13 19-3-2026
YAY i just done the firmware,however the usage of S and S2 button and Mode button and LED is not yet decided yet :D
I have made two different firmware files,for arduino and micropython.
Actually I'm not really good at arduino CPP coding but i think it does save more memory incase i wanna make a macro function to record my move and save them which may use a lot of memory?
[LINK to the firmware file](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/tree/main/firmware)
![Image of Arduino Programming](https://github.com/carlostmgps/Orange-Pi-5-Android-Handheld-Game-Console/blob/9e5cf21bc87036f233ab46124d8b0d2cbaca4186/image/Arduino%20Coding.png)
