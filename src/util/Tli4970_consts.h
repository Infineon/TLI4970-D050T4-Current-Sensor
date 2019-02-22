/**
 * Tli4970_consts.h - Part of the library for Arduino to control the TLI4970-D050T4 current sensor.
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

#ifndef TLI4970_CONSTS_H_INCLUDED
#define TLI4970_CONSTS_H_INCLUDED

#if defined(XMC1100_XMC2GO) || defined(XMC1100_H_BRIDGE2GO)
        #define TLI4970_STD_SPI				2
        #define TLI4970_STD_CS				3
        #define TLI4970_STD_DIO				0
#elif defined(XMC1100_Boot_Kit) ||defined(XMC1300_Boot_Kit) || defined(XMC1400_Boot_Kit) || defined(XMC4700_Relax_Kit)
	    #define TLI4970_STD_SPI				13
        #define TLI4970_STD_CS				10
        #define TLI4970_STD_DIO				12
#endif			

#define TLI4970_READOUT_ERROR		1
#define TLI4970_READOUT_SUCCESS		0

#define TLI4970_NUM_EEPROM_MASKS	16
#define TLI4970_NUM_EEPROM			7
#define TLI4970_NUM_STATUS			1


#endif
