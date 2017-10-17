/**
* @file circbuff.c
* @brief function definitions for interfacing and controlling a circular buffer
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "circbuff.h"


CB_status CB_buffer_add_item(CB_t * buff, uint32_t data){

  
  return 0;
};

CB_status CB_buffer_remove_item(CB_t * buff, uint32_t removedData);

CB_status CB_is_full(CB_t * buff);

CB_status CB_is_empty(CB_t * buff);

CB_status CB_peek(CB_t * buff, uint32_t buffValue);

CB_status CB_init(CB_t * buff, uint32_t length){

  buff->circbuff  = (uint32_t*)malloc((sizeof(size_t))*length);
  buff->headptr = buff->tailptr = buff->circbuff;

  buff->buffLength = length;   //setting the length of the buffer
  buff->count = 0;             //set current item count of buffer to zero
  
  if (buff->headptr == NULL)
  {
    return null_error;
  }
  else{
    return no_error;
  }
};

CB_status CB_destroy(CB_t * buff){
  if(buff != NULL)
  {
    free(buff);
    return no_error;
  }
  else
  {
    return null_error;
  }
};
