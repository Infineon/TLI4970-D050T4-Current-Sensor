/**
 * Tli4970.h - Library for Arduino to control the TLI4970-D050T4 current sensor.
 *
 * TLI4970 is a high-precision current sensor based on Infineon´s proven Hall technology. 
 * The coreless concept significantly reduces footprint compared with existing solutions. 
 * TLI4970 is an easy-to-use, fully digital solution that does not require external calibration 
 * or additional parts such as A/D converters, 0 pAmps or reference voltage. 
 * 
 * Have a look at the application note/reference manual for more information.
 * 
 * Copyright (c) 2018 Infineon Technologies AG
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:   
 *                                                                              
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 * disclaimer.                        
 * 
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 * disclaimer in the documentation and/or other materials provided with the distribution.                       
 * 
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written permission.                                           
 *                                                                              
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   
 */

#ifndef TLI4970_H_INCLUDED
#define TLI4970_H_INCLUDED

#include <SPI.h>
#include "util/Tli4970_consts.h"

class Tli4970
{
public:
	enum EEPROMregs_e
	{
		HP = 0, 
		PR,
		LP_SETTING, 
		INVERT_HADC, 
		IC_STAT, 
		OCD_OFF, 
		OVCL, 
		OVCF, 
		OCD_PP, 
		SR_OCD, 
		SR_DIO, 
		USR_LOCK, 
		GAIN, 
		CHIP_ID_2,
		CHIP_ID_1, 
		CHIP_ID_0
	};

	Tli4970(void);
	void begin(void);
	//void begin(SPIClass &bus, uint8_t pinCS, uint8_t pinDIO);
	//void end(void);
	
	void setSPIClockDivider(uint8_t div);
	
	uint8_t readOut(void);
	uint16_t getCurrMessage(void);
	float getCurrent(void);
	uint16_t getStatus(void);
	uint8_t getGeneralError();
	uint8_t getHardwareError();
	uint8_t getOverLoadError();
	uint8_t getOverTempError();
	uint8_t getCommunicationError();
	uint8_t getOverCurrent();
	
	void startConfiguration(void);
	
	// mask has to be a constant of the enum above
	// there are too many of them to write an own get- and setaccessor for each one
	uint16_t getEepromBits(uint8_t mask);
	void setEepromBits(uint8_t mask, uint16_t data);
	
	void abortConfiguration(void);
	void confirmConfiguration(void);

	void setPinOCD(uint8_t pinOCD);
	
private: 
	SPIClass *mBus;
	uint8_t mPinCS;
	// Define as signed integer to check definition
	int8_t mPinOCD;
	uint8_t mPinDIO;
	uint8_t mEnabled;
	uint8_t mConfigMode;
	uint16_t mStatus;
	uint16_t mEeprom[TLI4970_NUM_EEPROM];
	
	uint16_t getStatusBits(uint8_t mask);
	//uint16_t getEepromBits(uint8_t mask);
	//void setEepromBits(uint8_t mask, uint16_t data);
};


#endif