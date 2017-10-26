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

int main(){
  
 #ifdef PROJECT2
 project2();
 #endif

}
