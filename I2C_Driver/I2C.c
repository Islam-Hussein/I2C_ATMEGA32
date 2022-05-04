
/*
 * I2C.c
 *
 * Created: 5/2/2022 3:40:59 AM
 *  Author: Administrator
 */ 

#include "I2C.h"

void I2C_Init_Master(void)
{
	// Prescaler Set to 400KHz
	TWBR = 0x0C;
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);
	
	//Enabling I2C
	SET_BIT(TWCR, 2);
}

void I2C_Init_Slave(void)
{
	TWAR = (0x01 << 1);
	
	//Enabling I2C
	SET_BIT(TWCR, 2);
	
	//Enabling Global Calls
	SET_BIT(TWAR, 0);
	
}


void I2C_Start_Cond(void)
{
	// Monitor Bus and gnerate start Cond.
	SET_BIT(TWCR, 5);

	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
		
	//Clear Flag
	SET_BIT(TWCR, 7);
	
	//Stuck at while loop till the operation Finish	
	while(GET_BIT(TWCR , 7) == 0);
	
	while((TWSR & 0xF8) == START_ACK);	
}


void I2C_Repeated_Start(void)
{
	// Monitor Bus and gnerate start Cond.
	SET_BIT(TWCR, 5);

	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
		
	//Clear Flag
	SET_BIT(TWCR, 7);

	
	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);
	
	while((TWSR & 0xF8) == REP_START_ACK);	
}


void I2C_Send_SlaveAddress_Write_Operation(uint8 addr)
{
	TWDR = (addr << 1);

	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
	
	//Clear Flag
	SET_BIT(TWCR, 7);
	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);	
	
	while((TWSR & 0xF8) == SLAVE_ADD_RCVD_WR_RQST);
	
}


void I2C_Send_SlaveAddress_Read_Operation(uint8 addr)
{
	TWDR = (addr << 1) | (0x01);

	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
	
	//Clear Flag
	SET_BIT(TWCR, 7);
	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);
	
	while((TWSR & 0xF8) == SLAVE_ADD_RCVD_RD_RQST);
}


void I2C_Write_Byte(uint8 data)
{
	TWDR = data;

	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);	

	//Clear Flag
	SET_BIT(TWCR, 7);

	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);
	
	while((TWSR & 0xF8) == WR_BYTE_ACK);
	}


uint8 I2C_Read_byte(void)
{
	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
		
	//Clear Flag
	SET_BIT(TWCR, 7);
	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);
	
	while((TWSR & 0xF8) == RD_BYTE_WITH_ACK);	
}


void I2C_Stop_Cond(void)
{
	//Generate Stop Condition
	SET_BIT(TWCR,4);
	
	//Enabling I2C --> in order just to make sure that I2C is enabled
	SET_BIT(TWCR, 2);
	
	//Clear Flag
	SET_BIT(TWCR, 7);
	
	//Stuck at while loop till the operation Finish
	while(GET_BIT(TWCR , 7) == 0);
	
}
