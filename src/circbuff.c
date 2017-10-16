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


CB_status CB_buffer_add_item(CB_t * buff, uint32_t data);

CB_status CB_buffer_remove_item(CB_t * buff, uint32_t removedData);

CB_status CB_is_full(CB_t * buff);

CB_status CB_is_empty(CB_t * buff);

CB_status CB_peek(CB_t * buff, uint32_t buffValue);

CB_status CB_init(CB_t * buff, uint32_t length){

  buff = (CB_t *) malloc((sizeof(size_t)*length));

  if (buff == NULL)
  {
    return null_error;
  }
  else{
    return no_error;
  }
};

CB_status CB_destroy(CB_t * buff);
