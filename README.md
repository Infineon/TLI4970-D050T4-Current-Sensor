# TLI4970-Current-Sensor

[![Build Status](https://travis-ci.org/Infineon/TLI4970-D050T4-Current-Sensor.svg?branch=master)](https://travis-ci.org/Infineon/TLI4970-D050T4-Current-Sensor)

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/TLI4970_PP.jpg">

Library of Infineon's [TLI4970](https://www.infineon.com/cms/de/product/sensor/magnetic-current-sensor/tli4970-d050t4/) current sensor for Arduino.

## Summary
The [TLI4970](https://www.infineon.com/cms/de/product/sensor/magnetic-current-sensor/tli4970-d050t4/) is a high-precision current sensor based on Infineon's proven Hall technology. 
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
Please download this repository from GitHub by clicking on the following field in the latest [release](https://github.com/Infineon/TLI4970-Current-Sensor/releases) of this repository:

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Releases_Generic.jpg)

To install the TLI4970 current sensor library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **TLI4970**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please follow the example sketches in the /examples directory in this library to learn more about the usage of the library. For more information, please consult the datasheet [here](https://www.infineon.com/dgdl/Infineon-TLI4970-D050T4-DS-v01_01-EN.pdf?fileId=5546d4625607bd1301562c43e04f38ad).
