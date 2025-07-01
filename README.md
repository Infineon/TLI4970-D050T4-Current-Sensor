# TLI4970-Current-Sensor

[![Compile examples](https://github.com/Infineon/TLI4970-D050T4-Current-Sensor/actions/workflows/compile_examples.yml/badge.svg)](https://github.com/Infineon/TLI4970-D050T4-Current-Sensor/actions/workflows/compile_examples.yml)

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/TLI4970_PP.jpg" width=300>

Library of Infineon's [TLI4970](https://www.infineon.com/cms/en/product/sensor/current-sensors/tli4970-d050t4/) current sensor for Arduino.

## Summary
The [TLI4970](https://www.infineon.com/cms/en/product/sensor/current-sensors/tli4970-d050t4/) is a high-precision current sensor based on Infineon's proven Hall technology. 
The coreless concept significantly reduces footprint compared with existing solutions. TLI4970 is an easy-to-use, fully digital solution that does not require external calibration or additional parts such as A/D converters, 0 pAmps or reference voltage. It thus significantly reduces overall implementation efforts as well as PCB space and cost.

## Key Features and Benefits
* AC & DC measurement range up to ±50A
* Highly accurate over temperature range and lifetime (max. 1.0% (0 h), 
* 1.6% (over lifetime) of indicated value)
* Low offset error (max. 25mA)
* High magnetic stray field suppression
* Fast overcurrent detection with configurable threshold
* Galvanic isolation up to 2.5kV max. rated isolation voltage (UL1577)
* 16 bit digital SPI output (13 bit current value)
* Small 7 mm x 7 mm SMD package
* [GUI](https://www.infineon.com/cms/en/product/promopages/sensors-2go/#current-sensor-2go) for free download as well as integration in Arduino IDE with this repository

## Target Applications
* Photovoltaic and general purpose inverters
* Power supplies (SMPS)
* Battery chargers
* Lighting applications
* Electrical drives

## Hardware
Please find the datasheet of the TLI4970 variant [here](https://www.infineon.com/dgdl/Infineon-TLI4970-D050T4-DS-v01_01-EN.pdf?fileId=5546d4625607bd1301562c43e04f38ad). 
Please ensure that you have the TLI4970-D050T4 variant of the sensor as the library has been designed for this one.

## Installation

### Integration of Library

#### Prework
`Important Note`
This library uses the [One Wire](https://github.com/PaulStoffregen/OneWire) library from PaulStoffregen. Please install the One Wire library before you install or use the library for the TLI4970-D050T4 Current Sensor. You can find the One Wire library in the Library Manager in the Arduino IDE **Sketch** > **Include Library** > **Manage Libraries...** or directly in the official repository:

[One Wire Library Repository](https://github.com/PaulStoffregen/OneWire)

#### Installation of the Library

Please download this repository from GitHub by clicking on the following field in the latest [release](https://github.com/Infineon/TLI4970-Current-Sensor/releases) of this repository:

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Releases_Generic.jpg)

To install the TLI4970 current sensor library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **TLI4970**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please see the example sketches in the `/examples` directory in this library to learn more about the usage of the library.

Currently, there exist two separate evaluation boards:

* [TLI4970050 2 GO KIT](https://www.infineon.com/cms/en/product/promopages/sensors-2go/#current-sensor-2go)
* [TLI4970 CurrentSense Shield2Go](https://www.infineon.com/cms/en/product/evaluation-boards/s2go_cur-sense_tli4970/)

### Usage with TLI4970050 2 GO KIT
The Current Sensor 2GO is a budget-priced evaluation board equipped with the TLI4970-D050T4 current sensor combined with an ARM® Cortex™-M0 CPU. The Current Sensor 2GO has a complete set of on-board devices, including an on-board debugger. Build your own application and gadget with the Current Sensor 2GO.
More information can be found [here](https://www.infineon.com/cms/en/product/promopages/sensors-2go/#current-sensor-2go) as well.

Please note that base of the Sensors 2GO is the XMC 2Go from Infineon. Therefore, please install (if not already done) also the [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) implementation and choose afterwards **XMC1100 XMC2Go** from the **Tools**>**Board** menu in the Arduino IDE if working with this evaluation board.

### Usage with TLI4970 CurrentSense Shield2Go
The TLI4970 CurrentSense Shield2Go is a standalone break out board with Infineon's Shield2Go formfactor and pin out. You can connect it easily to any microcontroller of your choice which is Arduino compatible and has 3.3V logic level (please note that the Arduino UNO has 5V logic level and cannot be used without level shifting).

* [Link](https://github.com/Infineon/TLI4970-D050T4-Current-Sensor/wiki) to the wiki with more information

However, every Shield2Go is directly compatible with Infineon's XMC2Go and the recommended quick start is to use an XMC2Go for evaluation. Therefore, please install (if not already done) also the [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) implementation and choose afterwards **XMC1100 XMC2Go** from the **Tools**>**Board** menu in the Arduino IDE if working with this evaluation board. To use it, please plug the TLI4970 CurrentSense Shield2Go onto the XMC2Go as shown below.

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/TLI4970_S2Go_w_XMC2Go.png" width=250>

## Board Information, Datasheet and Additional Information

The datasheet for the TLI4970-D050T4 can be found here [TLI4970-D050T4 Datasheet](https://www.infineon.com/dgdl/Infineon-TLI4970-D050T4-DS-v01_01-EN.pdf?fileId=5546d4625607bd1301562c43e04f38ad) while respective application notes and more documents are located here [Application Notes](https://www.infineon.com/cms/en/product/sensor/current-sensors/tli4970-d050t4/#!documents).
The product page is located [here](https://www.infineon.com/cms/en/product/sensor/current-sensors/tli4970-d050t4/).

Please check the [wiki](https://github.com/Infineon/TLI4970-D050T4-Current-Sensor/wiki) with more information for the TLI4970 CurrentSense Shield2Go as well.
