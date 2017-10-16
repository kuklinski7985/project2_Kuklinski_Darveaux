/**
* @file circularBuffer.h
* @brief This file is used to declare the functions used to conver data from 
* one form to another.
* @author Andrew Kuklinski and Mason Darveaux
* @date 10-25-2017
**/


#include <stdio.h>
#include <stdint.h>

#ifndef circularBuffer_h_
#define circularBuffer_h_


typedef struct {

}CB_t;

typedef enum {

}CB_status;




<CB ​ ​ enum ​ ​ type> CB_destroy(<pointer ​ ​ of ​ ​ buffer ​ ​ type>);

<CB ​ ​ enum ​ ​ type> CB_init(<pointer ​ ​ of ​ ​ buffer ​ ​ type>, ​ ​ <length ​ ​ of ​ ​ buffer>);

<CB ​ ​ enum ​ ​ type> CB_peek(<buffer ​ ​ to ​ ​ peek ​ ​ into>, ​ ​ <position ​ ​ to ​ ​ peek>);

<CB ​ ​ enum ​ ​ type> CB_is_empty(<buffer ​ ​ to ​ ​ check>);

<CB ​ ​ enum ​ ​ type> CB_is_full(<buffer ​ ​ to ​ ​ check>);

<CB ​ ​ enum ​ ​ type> CB_buffer_remove_item(<buffer ​ ​ to ​ ​ remove ​ ​ from>, ​ ​ <variable ​ ​ to ​ ​ store ​ ​ data ​ ​ removed>);

<CB ​ ​ enum ​ ​ type> CB_buffer_add_item(<buffer ​ ​ to ​ ​ add ​ ​ to>, ​ ​ <data ​ ​ to ​ ​ add>);

#endif /*__circularBuffer_h__*/
