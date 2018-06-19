/**
 * Tli4970.cpp - Library for Arduino to control the TLI4970-D050T4 current sensor.
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

#include "Tli4970.h"
#include "util/RegMask.h"
#include "util/Tli4970_conf.h"
#include "util/SICI.h"

Tli4970::Tli4970(void)
{
	mBus = &SPI;
	mPinCS = TLI4970_STD_CS;
	mPinOCD = TLI4970_STD_OCD;
	mPinDIO = TLI4970_STD_DIO;
	mStatus = 0;
	mEnabled = false;
	mConfigMode = false;
}

void Tli4970::begin(void)
{
	mBus->begin();
	mBus->setDataMode(SPI_MODE1);
	pinMode(mPinCS, OUTPUT);
	pinMode(mPinOCD, INPUT);
	digitalWrite(mPinCS, HIGH);
	
	mEnabled = true;
}

void Tli4970::begin(SPIClass &bus, uint8_t pinCS, uint8_t pinOCD, uint8_t pinDIO)
{
	// Reconfigure mBus ,mPinCS ,mPinOCD and mPinDIO
	mBus = &bus;
	mPinCS = pinCS;
	mPinOCD = pinOCD;
	mPinDIO = pinDIO;
	
	begin();
}

void Tli4970::end(void)
{
	pinMode(mPinOCD, INPUT);
	pinMode(mPinCS, INPUT);
	mStatus = 0;
	mEnabled = false;
}

void Tli4970::setSPIClockDivider(uint8_t div)
{
	mBus->setClockDivider(div);
}

uint8_t Tli4970::readOut(void)
{
	uint8_t ret=1;
	digitalWrite(mPinCS, LOW);
	if(mEnabled && !mConfigMode)
	{
		mStatus = mBus->transfer16(0xFFFF);
		ret = tli4970::getFromRegs(&(tli4970::statusMasks[tli4970::ISSTATUS]), &mStatus);
	}
	digitalWrite(mPinCS, HIGH);
	return ret;
}

uint16_t Tli4970::getCurrMessage(void)
{
	if(!mEnabled || tli4970::getFromRegs(&(tli4970::statusMasks[tli4970::ISSTATUS]), &mStatus)) {
		return TLI4970_CURRENT_OFFSET;
	}
	else
	{
		return tli4970::getFromRegs(&(tli4970::statusMasks[tli4970::C_CURRENT]), &mStatus);
	}
}

float Tli4970::getCurrent(void)
{
	int16_t unscaled = getCurrMessage() - TLI4970_CURRENT_OFFSET;
	return unscaled / TLI4970_CURRENT_DIVIDER;
}

uint16_t Tli4970::getStatus(void)
{
	return mStatus;
}

uint8_t Tli4970::getGeneralError()
{
	return getStatusBits(tli4970::ISSTATUS);
}

uint8_t Tli4970::getHardwareError()
{
	return getStatusBits(tli4970::ISSTATUS) && getStatusBits(tli4970::HW_ERROR);
}

uint8_t Tli4970::getOverLoadError()
{
	return getStatusBits(tli4970::ISSTATUS) && getStatusBits(tli4970::OVERLOAD_ERROR);
}

uint8_t Tli4970::getOverTempError()
{
	return getStatusBits(tli4970::ISSTATUS) && getStatusBits(tli4970::OVERTEMP_ERROR);
}

uint8_t Tli4970::getCommunicationError()
{
	return getStatusBits(tli4970::ISSTATUS) && getStatusBits(tli4970::COM_ERROR);
}

uint8_t Tli4970::getOverCurrent()
{
	if(getStatusBits(tli4970::ISSTATUS))
	{
		return getStatusBits(tli4970::OVERLOAD_ERROR);
	}
	else
	{
		return getStatusBits(tli4970::C_OCD);
	}
}

uint16_t Tli4970::getStatusBits(uint8_t mask)
{
	return tli4970::getFromRegs(&(tli4970::statusMasks[mask]), &mStatus);
}

void Tli4970::startConfiguration(void)
{
	if(mEnabled)
	{
		tli4970::Sici bus = tli4970::Sici(mPinOCD);
		uint16_t cmd;
		bus.begin();
		bus.transfer16(tli4970::CMD_FREEZE);
		bus.transfer16(tli4970::CMD_REFRESH);
		cmd = tli4970::CMD_READ;
		tli4970::setToRegs(&tli4970::siciRegAdress, &cmd, tli4970::eepromRegAdrMap[0]);
		bus.transfer16(cmd);
		for(uint8_t i = 1; i < TLI4970_NUM_EEPROM; i++ )
		{
			cmd = tli4970::CMD_READ;
			tli4970::setToRegs(&tli4970::siciRegAdress, &cmd, tli4970::eepromRegAdrMap[i]);
			mEeprom[i-1] = bus.transfer16(cmd);
		}
		mEeprom[TLI4970_NUM_EEPROM-1] = bus.transfer16(cmd);
		bus.end();
		mConfigMode = true;
	}
}


uint16_t Tli4970::getEepromBits(uint8_t mask)
{
	if(mEnabled && mConfigMode && mask < TLI4970_NUM_EEPROM_MASKS)
	{
		return tli4970::getFromRegs(&(tli4970::eepromMasks[mask]), mEeprom);
	}
	else
	{
		return 0;
	}
}

void Tli4970::setEepromBits(uint8_t mask, uint16_t data)
{
	if(mask < TLI4970_NUM_EEPROM_MASKS)
	{
		tli4970::setToRegs(&(tli4970::eepromMasks[mask]), mEeprom, data);
	}
}

void Tli4970::abortConfiguration(void)
{
	pinMode(mPinOCD, INPUT);
	mConfigMode = false;
}

void Tli4970::confirmConfiguration(void)
{
	if(mEnabled && mConfigMode)
	{
		tli4970::Sici bus = tli4970::Sici(mPinOCD);
		bus.begin();
		for(uint8_t i = 0; i < TLI4970_NUM_EEPROM; i++ )
		{
			uint16_t cmd = tli4970::CMD_WRITE;
			tli4970::setToRegs(&tli4970::siciRegAdress, &cmd, tli4970::eepromRegAdrMap[i]);
			bus.transfer16(cmd);
			bus.transfer16(mEeprom[i]);
			bus.transfer16(tli4970::CMD_STORE_0);
			for(uint8_t i = 0; i<TLI4970_STORE_TIMEOUT; i++)
			{
				if(digitalRead(mPinDIO)==LOW)
				{
					break;
				}
			}
			cmd = tli4970::CMD_WRITE;
			tli4970::setToRegs(&tli4970::siciRegAdress, &cmd, tli4970::eepromRegAdrMap[i]);
			bus.transfer16(cmd);
			bus.transfer16(mEeprom[i]);
			bus.transfer16(tli4970::CMD_STORE_1);
			for(uint8_t i = 0; i<TLI4970_STORE_TIMEOUT; i++)
			{
				if(digitalRead(mPinDIO)==LOW)
				{
					break;
				}
			}
		}
		bus.transfer16(tli4970::CMD_REFRESH);
		bus.transfer16(tli4970::CMD_RESTART);
		bus.end();
		abortConfiguration();
	}
}


