/**
* @file uart.c
* @brief defines uart operation and provides functions for uart operation and initialization
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "uart.h"
#include "MKL25Z4.h"


void UART_configure()
{

uint8_t bdh; //used to set SBR bits in the BDH register, BAUD rate register High
uint8_t bdl; // used to set SBR bits in the BDL register, BAUD rate register low

uint16_t sbr_mask = 0;  // variable used to set the SBR field in the UART baud rate register in order to 
			// configure the baud rate

#ifdef UART0
SIM_SCGC4_REG |= UART0_CLK_GATE_MASK;  //enable clock signal to UART0 module

UART0_C2_REG &= ~(UART_C2_TE_MASK); //disables transmitter for UART 0
UART0_C2_REG &= ~(UART_C2_RE_MASK); //disables receiver for UART 0
UART0_C1_REG = 0; //sets UART C1 register to default, 8 bit packets, no parity

sbr_mask = BUSCLK/(16*BAUD); // sets 13 bit SBR value based on desired baud rate and system clock frequency

bdl = (uint8_t)(sbr_mask & 0x00FF); // masks out lower 8 SBR bits 
bdh = (uint8_t)((sbr_mask & 0x1F00)>>8); // masks out upper 5 SBR bits

UART0_BDL_REG = bdl;  //sets lower 8 SBR bits in UART0 BDL register
UART0_BDH_REG |= bdh; //sets the higher 5 SBR bits in the UART0 BDH register

UART0_C2_REG |= UART_C2_RIE_MASK; //enables interrupt generation for UART0 receiver
UART0_C2_REG |= UART_C2_TIE_MASK; //enables interrupt generation for UART0 transmitter

UART0_C2_REG |= UART_C2_TE_MASK;  //enable transmitter for UART 0
UART0_C2_REG |= UART_C2_RE_MASK;  //enable receiver for UART 0

#endif

#ifdef UART1
SIM_SCGC4_REG |= UART1_CLK_GATE_MASK;  //enable clock signal to UART module

UART1_C2_REG &= ~(UART_C2_TE_MASK); //disables transmitter for UART 
UART1_C2_REG &= ~(UART_C2_RE_MASK); //disables receiver for UART 
UART1_C1_REG = 0; //sets UART C1 register to default, 8 bit packets, no parity

sbr_mask = BUSCLK/(16*BAUD); // sets 13 bit SBR value based on desired baud rate and system clock frequency

bdl = (uint8_t)(sbr_mask & 0x00FF); // masks out lower 8 SBR bits 
bdh = (uint8_t)((sbr_mask & 0x1F00)>>8); // masks out upper 5 SBR bits

UART1_BDL_REG = bdl;  //sets lower 8 SBR bits in UART BDL register
UART1_BDH_REG |= bdh; //sets the higher 5 SBR bits in the UART BDH register

UART1_C2_REG |= UART_C2_RIE_MASK; //enables interrupt generation for UART receiver
UART1_C2_REG |= UART_C2_TIE_MASK; //enables interrupt generation for UART transmitter

UART1_C2_REG |= UART_C2_TE_MASK;  //enable transmitter for UART 
UART1_C2_REG |= UART_C2_RE_MASK;  //enable receiver for UART 

#endif

#ifdef UART2
SIM_SCGC4_REG |= UART2_CLK_GATE_MASK;  //enable clock signal to UART module

UART2_C2_REG &= ~(UART_C2_TE_MASK); //disables transmitter for UART 
UART2_C2_REG &= ~(UART_C2_RE_MASK); //disables receiver for UART 
UART2_C1_REG = 0; //sets UART C1 register to default, 8 bit packets, no parity

sbr_mask = BUSCLK/(16*BAUD); // sets 13 bit SBR value based on desired baud rate and system clock frequency

bdl = (uint8_t)(sbr_mask & 0x00FF); // masks out lower 8 SBR bits 
bdh = (uint8_t)((sbr_mask & 0x1F00)>>8); // masks out upper 5 SBR bits

UART2_BDL_REG = bdl;  //sets lower 8 SBR bits in UART BDL register
UART2_BDH_REG |= bdh; //sets the higher 5 SBR bits in the UART BDH register

UART2_C2_REG |= UART_C2_RIE_MASK; //enables interrupt generation for UART receiver
UART2_C2_REG |= UART_C2_TIE_MASK; //enables interrupt generation for UART transmitter

UART2_C2_REG |= UART_C2_TE_MASK;  //enable transmitter for UART 
UART2_C2_REG |= UART_C2_RE_MASK;  //enable receiver for UART 

#endif




}


void UART_send(uint8_t * data);
{

#ifdef UART0
	while (!(UART0_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

	UART0_D_REG = *data;  // transmit the byte by setting the UART data register
#endif

#ifdef UART1
	while (!(UART1_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

	UART1_D_REG = *data;  // transmit the byte by setting the UART data register
#endif

#ifdef UART2
	while (!(UART2_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

	UART2_D_REG = *data;  // transmit the byte by setting the UART data register
#endif

}



void UART_send_n(uint8_t * data, uint16_t length)
{
	int i;	//index variable


	for (i=0; i<length; i++)
	{
	#ifdef UART0
		while (!(UART0_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

		UART0_D_REG = *data;  // transmit the byte by setting the UART data register
	#endif

	#ifdef UART1
		while (!(UART1_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

		UART1_D_REG = *data;  // transmit the byte by setting the UART data register
	#endif

	#ifdef UART2
		while (!(UART2_S1 & UART_S1_TDRE_MASK)); // wait until transmit data register buffer is empty

		UART2_D_REG = *data;  // transmit the byte by setting the UART data register
	#endif

		data++; // increment the pointer to the array of data

	}

	data -= length;  //reset the the data pointer to its original value
}


uint8_t UART_receive(uint8_t * data);
{

#ifdef UART0
	while (!(UART0_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

	*data = UART0_D_REG;  // read data from UART data register into input variable

	return *data;  // return the byte of the data read from the UART receive data buffer

#endif

#ifdef UART1
	while (!(UART1_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

	*data = UART1_D_REG;  // read data from UART data register into input variable

	return *data;  // return the byte of the data read from the UART receive data buffer

#endif


#ifdef UART2
	while (!(UART2_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

	*data = UART2_D_REG;  // read data from UART data register into input variable

	return *data;  // return the byte of the data read from the UART receive data buffer

#endif


}


uint8_t * UART_receive_n(uint8_t * data, uint16_t length)
{

	int i; // index variable

	for (i=0; i<length; i++)
	{
	
	#ifdef UART0 
		while (!(UART0_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

		*data = UART0_D_REG; 	// read data from UART data register into input variable
	#endif

	#ifdef UART1
		while (!(UART1_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

		*data = UART1_D_REG; 	// read data from UART data register into input variable
	#endif

	#ifdef UART2 
		while (!(UART2_S1 & UART_S1_RDRF_MASK));	// wait until receive data buffer is full

		*data = UART2_D_REG; 	// read data from UART data register into input variable
	#endif
	
	data++;  //increment data pointer to point to next element of the array

	}

	data -= length; // resets the data pointer to its original value

	return data;  // return the pointer to the received array of byters

}

void UART0_IRQHandler()
{

	uint8_t tx_packet = 0xF0;  //packet to transmit on if TDRE flag is set
	uint8_t rx_packet = 0;	   //variable to store received packet if RDRF flag is set
	if(UART0_S1 & UART_S1_RDRF_MASK) 
	{
		rx_packet = UART0_D; // read data UART data register into input variabl
	}

	if(UART0_S1 & UART_S1_TDRE_MASK)
	{
		UART0_D = tx_packet;  //transmit dummy packet when TDRE flag is set
	}

}
