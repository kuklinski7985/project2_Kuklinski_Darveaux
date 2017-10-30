/**
* @file readme file
* @brief Project 2 for ECEN5813 - Fall 2017
*
*In project 2 we were required to create an interface between a terminal program and the KL25Z freedom board using UART.  This UART interface utilized several functions to read and write the receive / transmit buffer locally on the board.  In order to successfully process all the data that was sent, a circular buffer was implemented using a control struct and a dynamically allocated buffer.  These two systems were then used to process incomming data, keeping input statics.  These character statisics are printing the host terminal whent he buffer is full.
*
*
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/
