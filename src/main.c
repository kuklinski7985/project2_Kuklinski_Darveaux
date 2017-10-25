/**
* @file main.c
* @brief Main function call for Project 2 - ECEN5813
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


<<<<<<< HEAD
int main(){
  
 #ifdef PROJECT2
 project2();
 #endif

=======
int main()
{
 	uint8_t txdata = 0xF0;
	//uint8_t rxdata = 0;
	uint8_t* tx_address = &txdata;
	//uint8_t*rx_address = &rxdata;
	uint32_t i;

	for (;;)
	{
		i++;
		if (i==1000000)
		{
			i=0;
			UART_send(tx_address);
		}


	}




  /*#ifdef PROJECT2
 project2();
 #endif*/

/*
 CB_t userbuff;
 uint8_t size = 16;
CB_status status = 0;
status = CB_init(&userbuff,size);
printf("initialize status: %d\n\n",status);

 for(uint8_t y=1; y<=12; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
   printf("count: %d\n", userbuff.count);
 }

  for(uint8_t x=0; x<=7; x++)
 {
   status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
   printf("remove status: %d  |  removed data: %0x \n", status, *userbuff.poppedData);
   printf("count: %d\n", userbuff.count);
 }
 

   for(uint8_t y=1; y<=13; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
      printf("count: %d\n", userbuff.count);
 }
   

//  for(uint8_t x=1; x<5; x++)
// {
//   status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
//   printf("remove status: %d  |  removed data: %0x \n", status, *userbuff.poppedData);
//   }
  
   
 printf("\nBuffer Contents\n");

 print_memory(userbuff.circbuff, size);
 printf("headptr address: %p \n",userbuff.headptr);
 printf("tailptr address: %p \n",userbuff.tailptr);
*/
  return 0;
>>>>>>> 46b0a16c1c1ddfcee7fa14ca91cb157a6fd71804
}
