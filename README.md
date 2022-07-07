#### Cell-Phone-Detector-Robot-In-Examination-Hall

**Introduction**

There is a strong need to restrict mobile phone use in specific locations and at specific times. This project focuses on developing a system that would detect the existence of GSM signals from an illegal user in restricted locations such as examination halls, hospitals, and essential meeting places. To address this issue, I am going to develop an automated detection of cell phones. Keeping in mind that this project primarily focuses on creating a cell phone detecting robot, namely in examination halls where students abuse mobile phones by making concealed calls, internet access, data transfer, SMS, incoming and outgoing calls, and so on. The detector, which may be set at the entry or within an Examination-Hall, will be able to move within an Examination-Hall by following the line as it passes. When the detector detects signal from an active  cell phone or airplane or off mobile phone, the LED blinks, information is displayed on the LCD, and an real time notification is sent via GSM to the registered mobile number programmed in the microcontroller to notify the supervisor the presence of a mobile phone.


This project was simulated in Proteus Proffessional 8.13 and then implemented using actual devices. To simulate or develop this project, you need the following components.

**PART ONE: Hardware**
1. Arduino uno/any Arduino board (1)
2. SIM800L/ any GSM module (1)
3. IR Sensors (2)
4. Motor Wheels (2)
5. L293D motor driver (2)
6. Battery operated motors (2)
7. I2C LCD (1)
8. 5V Buzzer
9. LED (1)
10. Resistirs: 1K (3), 220R (1)
11. Switch (1)
12. RF detector (1) 
13. Metal detector sensor (1)
14. 3.7V 18650 Charger Li-ion Battery/relevant battery (3)

**PART TWO: Software**
1. Arduino IDE
2. Proteus Professional 8.13

## **SIMULATION IN PROTEUS SOFTWARE**
Before doing simualtion, perform the following steps/procedures
1. Install Proteus (if you don't have) in your Laptop/Desktop
2. Add arduino, ir sensor, gsm library in Proteus software. For more information and libraries please visit [theengineeringprojects.com](https://www.theengineeringprojects.com/2015/12/arduino-library-proteus-simulation.html)
3. Draw schematic circuit as shown in below or you can open the proteus file directly from above.
4. Install Arduino (if you don't have) and istal LiquidCrystal_I2C from here [Arduino-LiquidCrystal-I2C-library](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) by navigating to the Sketch -> Include Libray -> Add. ZIP.File in Arduino IDE.
5. Open the cell_phone_detecector_robot_in_examination_hall.ino
6. Compile the program and then coppy its path. For more information visit [How to upload an arduino code in proteus software](https://www.youtube.com/watch?v=0ciMTODrHZQ&ab_channel=Mechatronics)
7. Go to the proteus, after drawing your sketch. Double click the arduino and paste the pass you copied in Program File location and clock OK
8. Click the paly button to see how simulation is going.
9. Finally you made it.

## **ACTUAL IMPLEMENTATION**
For actual implementation, what you need to to set / wire the components as shown in schematic diagram, then uplad the codes to the arduino.
The designing of your robot it depends on you, you can change the parameters as you can in order to archieve your gaol. The schematic diagram is shown below.


  ![image](https://user-images.githubusercontent.com/65401201/177836704-58009465-ce7b-4154-9a26-bde97633b594.png)

If you want a complete mobile robot kit you can order one here [Avoidance Tracking Motor Smart Robot Car Chassis Kit Speed ​​Encoder Battery Box 2WD Ultrasonic Module for Arduino kit](https://es.aliexpress.com/item/32541422454.html?spm=a2g0o.productlist.0.0.74c96cd6XMojNG&algo_pvid=0a2357eb-d4d8-4953-8677-45213ad20f7e&algo_exp_id=0a2357eb-d4d8-4953-8677-45213ad20f7e-8&pdp_ext_f=%7B%22sku_id%22%3A%2210000000912275308%22%7D&pdp_npi=2%40dis%21TZS%21%2147179.14%21%21%21%21%21%402101e9d416572161632094191eab6f%2110000000912275308%21sea)
