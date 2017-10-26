/**
* @file project2.c
* @brief Defines the data processing portion of Project2, ECEN5816.  Uses
* UART and circular buffer constructions to track statistics of input
* character values
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "circbuff.h"
#include "uart.h"
#include "debug.h"
#include "project2.h"

uint8_t Alpha_count=0;
uint8_t Num_count=0;
uint8_t Punct_count=0;
uint8_t Misc_count=0;
uint8_t error_count=0;


void project2(void)
{




}

void process_Data(uint8_t data)
{

	if(65<=data<=90 || 97<=data<=122) 	//check if data is an alphabetical character in ASCII
	Alpha_count++;

	else if(48<=data<=57)			//check if data is a number in ASCII
	Num_count++;

	else if(32<=data<=47 || 58<=data<=64 || 91<=data<=96 || 123<=data<=126) // check if data is punctuation in ASCII
	Punct_count=0;

	else if(0<=data<=31 || data==127)
	Misc_count++;
	
	else
	error_count++;

  printf("%c",getc(stdin));
  return;
  

}

void transmit_table()
{
	uint8_t Alpha[] = "# of Alphabetic Characters:  ";
	uint16_t Alpha_Length = 29;
	uint8_t Num[] = "# of Numeric Characters:  ";
	uint16_t Num_Length = 26;
	uint8_t Punct[] = "# of Punctuation Characters:  ";
	uint16_t Punct_length = 29;
	uint8_t Misc[] = "# of Miscellaneous Characters:  ";
	uint16_t Misc_length = 32;

	UART_send_n(Alpha, Alpha_Length);

	UART_send(&Alpha_count);

	
	UART_send_n(Num, Num_Length);

	UART_send(&Num_count);

	
	UART_send_n(Punct, punct_Length);

	UART_send(&Punct_count);

	
	UART_send_n(Misc, Misc_Length);

	UART_send(&Misc_count);

}




	
	









