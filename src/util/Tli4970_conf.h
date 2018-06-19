/**
 * Tli4970_conf.h - Part of the library for Arduino to control the TLI4970-D050T4 current sensor.
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

#ifndef TLI4970_CONF_H_INCLUDED
#define TLI4970_CONF_H_INCLUDED

#include "RegMask.h"

#define TLI4970_CURRENT_OFFSET		4096
#define TLI4970_CURRENT_DIVIDER		80.0
#define TLI4970_STORE_TIMEOUT		128

namespace tli4970
{
		
enum ResponseFlags_e
{
	ISSTATUS = 0,
	PARITY, 
	C_OCD, 
	C_CURRENT, 
	HW_ERROR, 
	OVERLOAD_ERROR,
	OVERTEMP_ERROR,
	COM_ERROR
};

const int eepromRegAdrMap[] = { 0, 1, 2, 3, 13, 14, 15 };

const RegMask_t eepromMasks[] = 
{
	{ REGMASK_WRITE, 0, 0x0800, 11 }, 
	{ REGMASK_WRITE, 0, 0x0400, 10 }, 
	{ REGMASK_WRITE, 0, 0x0380, 7 }, 
	{ REGMASK_WRITE, 0, 0x0040, 6 }, 
	{ REGMASK_WRITE, 0, 0x0007, 0 }, 
	{ REGMASK_WRITE, 1, 0x8000, 15 }, 
	{ REGMASK_WRITE, 1, 0x1F00, 8 }, 
	{ REGMASK_WRITE, 1, 0x000F, 0 }, 
	{ REGMASK_WRITE, 2, 0x4000, 14 }, 
	{ REGMASK_WRITE, 2, 0x3000, 12 }, 
	{ REGMASK_WRITE, 2, 0x0C00, 10 }, 
	{ REGMASK_WRITE, 2, 0x0010, 4 }, 
	{ REGMASK_WRITE, 3, 0xFFFF, 0 }, 
	{ REGMASK_WRITE, 4, 0xFFFF, 0 }, 
	{ REGMASK_WRITE, 5, 0xFFFF, 0 }, 
	{ REGMASK_WRITE, 6, 0xFFFF, 0 }
};

const RegMask_t statusMasks[] = 
{
	{ REGMASK_READ, 0, 0x8000, 15 }, 
	{ REGMASK_READ, 0, 0x4000, 14 }, 
	{ REGMASK_READ, 0, 0x2000, 13 }, 
	{ REGMASK_READ, 0, 0x1FFF, 0 }, 
	{ REGMASK_READ, 0, 0x2000, 13 }, 
	{ REGMASK_READ, 0, 0x1000, 12 }, 
	{ REGMASK_READ, 0, 0x0800, 11 }, 
	{ REGMASK_READ, 0, 0x0400, 10 }, 
};


enum siciCommands_e
{
	CMD_FREEZE = 0xAABF,
	CMD_REFRESH = 0x8018,
	CMD_RESTART = 0x7FFF,
	CMD_READ = 0x8000,
	CMD_WRITE = 0x8001,
	CMD_STORE_0 = 0x841A,
	CMD_STORE_1 = 0x841B
};

const RegMask_t siciRegAdress = 
{ REGMASK_WRITE, 0, 0x3F00, 8 };





}

#endif