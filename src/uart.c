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

void UART_configure();

void UART_send(uint32_t * data);

void UART_send_n(uint32_t * data, uint32_t length);

uint32_t UART_receive(uint32_t * inputData);

uint32_t UART_receive_n(uint32_t * data, uint32_t length);

void UART0_IRQHandler();
