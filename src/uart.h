/**
* @file uart.h
* @brief creating a UART interface in order to have a method of transmitting
         and receiving data to development board
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/


#include <stdio.h>
#include <stdint.h>

#ifndef uart_h_
#define uart_h_

#define UART_C2_TE_MASK 0b0001000   	//bit 3
#define UART_C2_RE_MASK 0b0000100  	//bit 2
#define UART0_CLK_GATE_MASK 0x00000400	//bit 10
#define UART1_CLK_GATE_MASK 0x00000800  //bit 11
#define UART2_CLK_GATE_MASK 0x00001000  //bit 12
#define UART_C2_RIE_MASK 0x20   	//bit 5
#define UART_C2_TIE_MASK 0x80  		//bit 7
#define UART_S1_TDRE_MASK 0x80          //bit 7
#define UART_S1_RDRF_MASK 0x20		//bit 5
#define BUSCLK 20971520u // default system clock is 20.971 MHz
#define BAUD 38400 // define UART baud rate here

#define UART0
//#define UART1
//#define UART2




/**
 *@brief configures UART
 *
 *@param none
 *
 *@return VOID
 */
void UART_configure();


/**
 *@brief sends a single btye down a specific UART device, should block  on transmitting data
 *
 *@param "data" data to be sent
 *
 *@return VOID
 */
void UART_send(uint8_t * data);


/**
 *@brief transmits a continuous block of data
 *
 *@param "data" pointer to data to be transmitted
 *@param "length" length of data to be transmitted
 *
 *@return VOID
 */
void UART_send_n(uint8_t * data, uint16_t length);


/**
 *@brief receives a single byte of data, should block until character is received
 *
 *@param "inputData"
 *
 *@return byte of data that was sent
 */
uint8_t UART_receive(uint8_t * data);


/**
 *@brief receives a number of bytes on the UART
 *
 *@param "data" pointer to memory location to place data that is being received
 *@param "length" number of items to receive
 *
 *@return
 */
uint8_t * UART_receive_n(uint8_t * data, uint16_t length);


/**
 *@brief handles receive and transmitt interrups and clears their associated flag when completed but only if they were set
 *
 *@param none
 *
 *@return VOID
 */
void UART0_IRQHandler();


#endif /*__uart_h__*/
