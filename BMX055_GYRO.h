/* Code written by Chia Jiun Wei @ 31 Aug 2017
 * <J.W.Chia@tudelft.nl>
 
 * BMX055_GYRO: a library to provide high level APIs to interface with 
 * the Bosch Absolute Orientation Sensors gyroscope. It is  
 * possible to use this library in Energia (the Arduino port for 
 * MSP microcontrollers) or in other toolchains.
 
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 
 * version 3, both as published by the Free Software Foundation.
  
 */
 
#ifndef BMX055_GYRO_H
#define BMX055_GYRO_H

#include <Energia.h>
#include <DSPI.h>

#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include "bmg160.h"

#ifdef __cplusplus
}
#endif
	
	//Read write function interface with Bosch gyroscope bmg160 API
	s8 readRegister(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 size);
	s8 writeRegister(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 size);
	void delay_msek(u32 msek);
	
class BMX055_GYRO

{
protected:	
	
	bmg160_t bmg160;
	
public:
	
	BMX055_GYRO(DSPI *spi, unsigned char pin);
	virtual ~BMX055_GYRO( ) {};
	
	void init();
	signed char ping();
	void get_gyro(s16 *data_array);
	
private:	
	
};


#endif  // BMX055_GYRO_H