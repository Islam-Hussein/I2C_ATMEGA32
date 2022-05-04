
/*
 * I2C.h
 *
 * Created: 5/2/2022 3:40:47 AM
 *  Author: Administrator
 */ 

#ifndef I2C_H_
#define I2C_H_

#include "ATMEGA32_REGISTERS.h"
#include "STD_MATH.h"

#define START_ACK				  0x08  // Start has been sent
#define REP_START_ACK			  0x10  // Repeated Start
#define SLAVE_ADD_AND_WR_ACK	  0x18  // Master Transmitted (slave address + write request) ACK
#define SLAVE_ADD_AND_RD_ACK	  0x40  // Master Transmitted (slave address + read request) ACK
#define WR_BYTE_ACK				  0x28  // Master Transmit Data ACK
#define RD_BYTE_WITH_NACK         0x58  // Master Received Data with not ACK
#define RD_BYTE_WITH_ACK          0x50  // Master Received Data with ACK
#define SLAVE_ADD_RCVD_RD_RQST    0xA8  // Means that slave address is received with Write REQ
#define SLAVE_ADD_RCVD_WR_RQST    0x60  // Means that slave address is received with Read REQ
#define SLAVE_DATA_RECEIVED		  0xB0  // Means that Read BYTE REQ is received
#define SLAVE_BYTE_TRANSMITTED    0xC0  // Means that Write BYTE REQ is received




void I2C_Init_Master(void);

void I2C_Init_Slave(void);

void I2C_Start_Cond(void);

void I2C_Repeated_Start(void);

void I2C_Send_SlaveAddress_Write_Operation(uint8 addr);

void I2C_Send_SlaveAddress_Read_Operation(uint8 addr);

void I2C_Write_Byte(uint8 data);

uint8 I2C_Read_byte(void);

void I2C_Stop_Cond(void);





#endif  /* I2C_H_ */
