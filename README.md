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
12. RF detector (1) (Refer to the cell_phone_rf_detector_circuit)
13. Metal detector sensor (1)
14. 3.7V 18650 rechargeable li-ion Battery/relevant battery (3)

**PART TWO: Software**
1. Arduino IDE
2. Proteus Professional 8.13

## **Simulation in Proteus Software**
Before doing simualtion, perform the following steps/procedures
1. Clone https://github.com/Myjofe/Cell-Phone-Detector-Robot-In-Examination-Hall
2. Install Proteus (if you don't have) in your Laptop/Desktop
3. Add arduino, ir sensor, gsm libraries in Proteus software. For more information and libraries please visit [theengineeringprojects.com](https://www.theengineeringprojects.com/2015/12/arduino-library-proteus-simulation.html)
4. Open _cell_phone_detector_arduino_uno.pdsprj Proteus file._
5. Install Arduino from [Arduino](https://www.arduino.cc/en/software) (if you don't have) 
6. Add LiquidCrystal_I2C library i Arduino IDE from here [Arduino-LiquidCrystal-I2C-library](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) by navigating to the Sketch -> Include Libray -> Add. ZIP.File in Arduino IDE.
7. Open the _cell_phone_detecector_robot_in_examination_hall.ino_
8. Compile the program and then coppy its path. For more information visit [How to upload an arduino code in proteus software](https://www.youtube.com/watch?v=0ciMTODrHZQ&ab_channel=Mechatronics)
9. Go to the proteus, in your sketch. Double click the arduino and paste the pass you copied in Program File location and click OK
10. Click the play button to simulate the project.


## **Actual Implimentation**
For actual implementation, what you are needed is to set / wire the components as shown in schematic diagram, then upload the codes to the arduino.
The designing and appearence of your robot will depend on you, you can change the parameters as you wish in order to archieve your gaol. The schematic diagram of whole system is shown below.

![cell_phone_detector_robot_circuit](https://user-images.githubusercontent.com/65401201/178110484-c3924a64-6541-4ed1-8ac0-84edffa9592b.JPG)

 
 
If you want a complete mobile robot kit you can order one here [Avoidance Tracking Motor Smart Robot Car Chassis Kit Speed ​​Encoder Battery Box 2WD Ultrasonic Module for Arduino kit](https://es.aliexpress.com/item/32541422454.html?spm=a2g0o.productlist.0.0.74c96cd6XMojNG&algo_pvid=0a2357eb-d4d8-4953-8677-45213ad20f7e&algo_exp_id=0a2357eb-d4d8-4953-8677-45213ad20f7e-8&pdp_ext_f=%7B%22sku_id%22%3A%2210000000912275308%22%7D&pdp_npi=2%40dis%21TZS%21%2147179.14%21%21%21%21%21%402101e9d416572161632094191eab6f%2110000000912275308%21sea)


## **Cell Phone RF detector**
This detector is used to capture FR emitted from a cell phone when in active mode. Here, you are required to design a RF detector, to simplify, open the proteus file named  _**cell_phone_RF_detector.pdsprj**_ . There is schematic diagram, PCB layout and 3D View. From there you can print and solder your own RF detector circuit.
The range of detection is based on the commponents used and the strenght of the siginal from a targeted cell phone. There are lot of cell phone RF detectors already discussed online so, you can build tour own circuit.

## **Metal Detector Senosr**
The use of this part is to detect a cell phone which is kept in inactive or airplane mode. There are lot of metal detector with different applications. You can search ametal detector online and choose one which will be easier and fulfil your needs.
You can replace metal detector with another sensor which you see can be the best to detect a cell phone that is not in active mode. This is the metal detector circuit that I choose, it has high snsitivity and will provide you better results to detect a cell phone which is not in active mode.
[DIY Metal Detector | Russian metal detector circuit | Pirate](https://www.youtube.com/watch?v=7QJrI-9CCIw&ab_channel=DHTProject)

**NOTE**
In order to read the inputs from these detectors, you need to interface the detectors with the microcontroller as shown in the schematic circuit above by reading their outputs.
