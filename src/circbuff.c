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


CB_status CB_buffer_add_item(CB_t * buff, uint32_t data)
{
  if(CB_is_full(buff) == buffer_full)  //checks to see if buffer is full
  {
    return buffer_full;
  }
  else
  {
    //*buff->headptr = data;
    buff->count++;
  }

  /*checks coniditions for wrap around, if true then sets back to start
  * else increases headptr to next location*/
  
  if(((buff->headptr)+1) == ((buff->circbuff) + (buff->buffLength)))
  {
    buff->headptr = buff->circbuff;
    printf("end buffer\n");
  }
  else
  {
    buff->headptr++;
    printf("increment headptr\n");
  }
  
  return no_error;
};



CB_status CB_buffer_remove_item(CB_t * buff, uint32_t removedData);

CB_status CB_is_full(CB_t * buff)
{
  //if(((buff->headptr - buff->tailptr) & (buff->buffLength -1)) == (buff->buffLength - 1))
  if(buff->count == (buff->buffLength-1))
  {
    return buffer_full;
  }
  else
  {
    return no_error;
  }
};

CB_status CB_is_empty(CB_t * buff);

CB_status CB_peek(CB_t * buff, uint32_t buffValue);

CB_status CB_init(CB_t * buff, uint32_t length){

  buff->circbuff  = (uint8_t*)malloc((sizeof(size_t))*length);
  buff->headptr = buff->circbuff;
  buff->tailptr = buff->circbuff;

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
  if(buff == NULL)
  {
    return null_error;
  }
  else
  {
    free(buff);
    return no_error;
  }
};
