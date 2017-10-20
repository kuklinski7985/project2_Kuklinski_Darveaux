
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "circbuff.h"
#include "uart.h"
#include "debug.h"



int main(){
  
  /*#ifdef PROJECT2
 project2();
 #endif*/

 CB_t userbuff;
 uint8_t size = 8;
CB_status status = 0;
status = CB_init(&userbuff,size);
printf("initialize status: %d\n\n",status);

 for(uint8_t y=1; y<4; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
 }

  for(uint8_t x=1; x<2; x++)
 {
   status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
   printf("remove status: %d  |  removed data: %0x \n", status, *userbuff.poppedData);
 }
 
  
   for(uint8_t y=1; y<5; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
 }


  for(uint8_t x=1; x<5; x++)
 {
   status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
   printf("remove status: %d  |  removed data: %0x \n", status, *userbuff.poppedData);
 }
  
   
 printf("\nBuffer Contents\n");

 print_memory(userbuff.circbuff, size);
 printf("headptr address: %p \n",userbuff.headptr);
 printf("tailptr address: %p \n",userbuff.tailptr);
  return 0;
}




