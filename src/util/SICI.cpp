/**
 * SICI.cpp - Part of the library for Arduino to control the TLI4970-D050T4 current sensor.
 *
 * TLI4970 is a high-precision current sensor based on Infineon´s proven Hall technology. 
 * The coreless concept significantly reduces footprint compared with existing solutions. 
 * TLI4970 is an easy-to-use, fully digital solution that does not require external calibration 
 * or additional parts such as A/D converters, 0 pAmps or reference voltage. 
 * 
 * Have a look at the application note/reference manual for more information.
 * 
 * This file uses the OneWire library, originally developed by Jim Studt and many contributors since then.
 * Please have a look at the OneWire library for additional information about the license, copyright, and contributors.
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

#include "SICI.h"

#define TLI4970_SICI_FRAMEPAUSE		40

tli4970::Sici::Sici(uint8_t pin)
{
	mActive = false;
	mInterface = nullptr;
	mPin = pin;
}

void tli4970::Sici::begin(void)
{
	mInterface = new OneWire(mPin);
	mActive = true;
}

void tli4970::Sici::end(void)
{
	delete mInterface;
	mInterface = nullptr;
	mActive = false;
}

uint16_t tli4970::Sici::transfer16(uint16_t dataIn)
{
	int8_t i;
	uint16_t dataOut=0;
	if(mActive == true)
	{
		for(i=15; i>=0; i--)
		{
			write_bit((dataIn>>i) & 0x01);
			dataOut |= (read_bit()) << i;
		}
		delayMicroseconds(TLI4970_SICI_FRAMEPAUSE);
		return dataOut;
	}
	else
	{
		return 0;
	}
}

uint8_t tli4970::Sici::read_bit(void)
{
	// 1 is a long low pulse, 0 is a short low pulse
	// exactly different from onewire, so we have to invert it
	return !(mInterface->read_bit());
}

void tli4970::Sici::write_bit(uint8_t value)
{
	// 1 is a long low pulse, 0 is a short low pulse
	// exactly different from onewire, so we have to invert it
	mInterface->write_bit(!value);
}
