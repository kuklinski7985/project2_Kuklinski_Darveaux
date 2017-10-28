/**
* @file unittesting.c
* @brief Contains functions definitions and main function for unittesting
* using CMOCKA framework and libraries.  Makefile present to run the 
* testing and create .exe file.
* @author Andrew Kuklinski and Mason Darveaux
* @date 10/25/2017
**/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.c"
#include "conversion.c"
#include "circbuff.c"

/********************************************************/
/*************Unit Testing for memory.c******************/
/********************************************************/

/**
 *@brief Tests for invalid pointers sent to the function my_memmove, returns
 *a failure status when pointers are NULL
 *
 *@return returns a test failure when pointers are NULL
 */

static void memmoveTestVoid(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = NULL;
  testsrc = NULL;
  assert_true(my_memmove(testsrc, testdst, 8) == NULL);
}

/**
 *@brief Tests for no overlap in the desitation and sources memory locations
 *in my_memmove.  
 *@return returns a test pass / success when move is completed
 */
static void memmoveTestNoOverlap(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = &testptrdst;
  testsrc = &testptrsrc;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
}

/**
 *@brief Tests to see if source/destination memory locations are within
 * destination/source memory locations within my_memmove. 
 *@return returns a test pass / success even with overlap
 */
static void memmoveTestWithOverlap(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = &testptrdst;
  testsrc = &testptrsrc;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
}

/**
 *@brief Tests for invalid input pointers into my_memset.
 *
 *@return Returns a test failure when pointers are null.
 */
void memsetTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_memset(testsrc,8,3) == NULL);
}

/**
 *@brief Tests checks to validate that proper values are written
 *to all memory locations, for the entire length using my_memset.
 *
 *@return Returns a pass / success if all memory locations are correct
 */
static void memsetTestCheckSet(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = &testptrsrc;

  uint8_t length = 8;
  uint8_t value = 4;
  
  uint8_t * test2 = my_memset(testsrc,length,value);

  for(uint8_t i=0;i<length;i++)
    {
      if(*(test2+i) != value)
	{
	  assert_true(value != *(test2+i));
	}
    }
  assert_true(value == *(test2+length));
}

/**
 *@brief Tests input pointers for NULL using my_memzero.
 *
 *@return Returns a test failure when pointers are NULL.
 */
static void memZeroTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_memzero(testsrc,8) == NULL);
}

/**
 *@briefTests checks to validate that zeros are written
 *to all memory locations, for the entire length using my_memset.
 *
 *@return Returns a test pass / success when all memory locations
 *are set to zero
 */
static void memZeroTestCheckSet(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = &testptrsrc;
  uint8_t length = 8;
  
  uint8_t * test2 = my_memzero(testsrc,length);

  for(uint8_t i=0;i<length;i++)
    {
      if(*(test2+i) != 0)
	{
	  assert_true(*(test2+i)==0);
	}
    }
  assert_true(*(test2+length)==0);
}


/**
 *@brief Tests for invalid pointers as input to my_reverse fxn
 *
 *@return Returns a test failure when inputs are NULL
 */
static void reverseTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_reverse(testsrc,8) == NULL);
}

/**
 *@brief Tests that an odd number of values are sucessfully
 *reversed when using my_reverse
 *
 *@return Returns a test pass / success if successful
 */
static void reverseTestOdd(void** state)
{
  uint8_t * testsrc;
  char testptrsrc[] = "abcde";
  testsrc = testptrsrc;
  size_t length = 5;

  my_reverse(testsrc, length);
  
  char correctReverse[] = "edcda";

  uint8_t i=0;
  for(i=0; i<=length; i++)
    {
      if(*(correctReverse+i) != *(testsrc+i))
	{
	  assert_true(*(correctReverse+i) != *(testsrc+i));
	}
    }
  assert_true(my_reverse(testsrc,length) != NULL);
  
}

/**
 *@brief Tests an even number of values are sucessfully
 *reversed when using my_reverse
 *
 *@return Returns a pass / success if all values are correct
 */
static void reverseTestEven(void** state)
{
  uint8_t * testsrc;
  char testptrsrc[] = "abcdef";
  testsrc = testptrsrc;
  size_t length = 6;

  my_reverse(testsrc, length);
  
  char correctReverse[] = "fedcba";

  uint8_t i=0;
  for(i=0; i<=length; i++)
    {
      if(*(correctReverse+i) != *(testsrc+i))
	{
	  assert_true(*(correctReverse+i) != *(testsrc+i));
	}
    }
  assert_true(my_reverse(testsrc,length) != NULL);
  
}

/**
 *@brief Tests the ability to reverse any character set
 * using my_reverse function
 *
 *@return Returns a test pass / success if character independent
 */
static void reverseTestChar(void** state)
{
  uint8_t * testsrc;
  char testptrsrc[] = "!@# $%^";
  testsrc = testptrsrc;
  size_t length = 7;

  my_reverse(testsrc, length);
  
  char correctReverse[] = "^%$ #@!";

  uint8_t i=0;
  for(i=0; i<=length; i++)
    {
      if(*(correctReverse+i) != *(testsrc+i))
	{
	  assert_true(*(correctReverse+i) != *(testsrc+i));
	}
    }
  assert_true(my_reverse(testsrc,length) != NULL);  
}

/********************************************************/
/**********Unit Testing for conversion.c*****************/
/********************************************************/


/**
 *@brief Tests for invalid pointers as input to 
 * big_to_little32 function.
 *
 *@return Returns a test failure if a NULL pointer
 */
static void bigToLittleTestVoid(void** state)
{
  uint32_t * testsrc;
  uint32_t testptrsrc;
  testsrc = NULL;
  assert_true(big_to_little32(testsrc,1) == 1);
}

/**
 *@brief Test the valid conversion of big to little endian
 * using big_to_little32 function
 *
 *@return Returns a test pass / success if successful
 */
static void bigToLittleTestValid(void** state)
{
  uint32_t * testsrc;
  uint32_t testData = 0xAB12CD34;
  testsrc = &testData;
  assert_true(big_to_little32(testsrc,1) == 0);
}

/**
 *@brief Tests for invalid pointers as input to
 * little_to_big32 function.
 *
 *@return Returns a test failure if a NULL pointer is used
 */
static void littleToBigTestVoid(void** state)
{
  uint32_t * testsrc;
  uint32_t testptrsrc;
  testsrc = NULL;
  assert_true(big_to_little32(testsrc,1) == 1);
}

/**
 *@brief  Test for valid conversion of little to big endian
 * using little_to_big32 function
 *
 *@return Returns a test pass / success in successful
 */
static void littleToBigTestValid(void** state)
{
  uint32_t * testsrc;
  uint32_t testData = 0xAB12CD34;
  testsrc = &testData;
  assert_true(big_to_little32(testsrc,1) == 0);
}

/********************************************************/
/**************Circular Buffer Test Functions************/
/********************************************************/


/**
 *@brief Test checks that a dynamic buffer has been created
 * using the CB_init function
 *
 *@return Returns a pass / success if an address is returned
 */
static void bufferAllocateTest(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(&userbuff,length) == no_error);
  
}

/**
 *@brief Test checks for an invalid pointer as input
 * to the CB_init function.
 *
 *@return Returns a test failure if NULL pointer is used.
 */
static void bufferPtrTestValid(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(NULL,length) == null_error);
}

/**
 *@brief Tests whether or not a valid buffer has been
 * created using the CB_init function
 *
 *@return Returns a test failure if no valid buffer 
 *has been created. 
 */
static void bufferNonInitTest(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(&userbuff,length) == no_error);
}

/**
 *@brief Tests condition that the same values are returned
 *for the full length of the buffer when using CB_buffer_add_item
 * and the CB_buffer_write_item functions.
 *
 *@return Returns a test pass / success if all values match.
 */
static void bufferTestAddRemove(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff, 16);
  uint32_t data = 0;
  CB_status status;
  uint8_t writeComp = 0;
  uint8_t readComp = 0;
  
  
  for(uint8_t i=0; i < userbuff.buffLength; i++)
    {
      CB_buffer_add_item(&userbuff, (60+i));
      CB_peek(&userbuff,i,userbuff.poppedData);
      writeComp = *(userbuff.poppedData);
      CB_buffer_remove_item(&userbuff,userbuff.poppedData);
      CB_peek(&userbuff,i,userbuff.poppedData);
      readComp = *(userbuff.poppedData);
      if(writeComp != readComp)
	{
	  assert_false(writeComp == readComp);
	}
    }
  assert_true(writeComp == readComp);
}

/**
 *@brief Tests the buffer full condition using the CB_is_full
 *function via the CB_buffer_add_item function.
 *
 *@return returns a enum status of "buffer_full", test pass / successful
 *if buffer is full
 */
static void bufferTestFull(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;
  for(uint8_t i=0; i<= 17; i++)
    {
      status = CB_buffer_add_item(&userbuff,i);
    }
  assert_true(status == buffer_full);
}

/**
 *@brief Test checks if buffer is empty using the CB_is_empty
 *function nested in CB_buffer_remove_item function
 *
 *@return Returns an enum type of buffer_empty, test pass / successful
 */
static void bufferTestEmpty(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = CB_buffer_remove_item(&userbuff,0);
  assert_true(status == buffer_empty);
}

/**
 *@brief Tests that the buffer can wrap around the edge boundary 
 *and add to the front of the buffer using the CB_buffer_add_item function
 *
 *@return Returns a test pass / success if the wrap is successful
 */
static void bufferTestWrapAroundADD(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;
  uint8_t testLength = 9;
  userbuff.headptr = userbuff.circbuff + 9;
  for(uint8_t i=0; i<= testLength; i++)
    {
      status = CB_buffer_add_item(&userbuff,i);
    }

  assert_true(status == no_error);
}

/**
 *@brief tests taht the buffer tail pointer can wrap around
 * the edge boundary when a remove occurs using the 
 *CB_buffer_remove_item function
 *
 *@return 
 */
static void bufferTestWrapAroundREMOVE(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;
  uint8_t testLength = 9;


  for(uint8_t x=0;x<=1;x++)
    {
      for(uint8_t i=0;i<=testLength;i++)
      {
        CB_buffer_add_item(&userbuff,i);
      }

      for(uint8_t j=0;j<=testLength;j++)
      {
        status = CB_buffer_remove_item(&userbuff, userbuff.poppedData);
      }
    }
  assert_true(status == no_error);
}

/**
 *@brief  Test that the buffer fails when too many items are added
 * using the CB_buffer_add item and CB_buffer_remove_item functions
 *
 *@return Returns a test failure if buffer is over filled
 */
static void bufferTestOverFill(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;

  for(uint8_t y=1; y<=12; y++)
    {
      status = CB_buffer_add_item(&userbuff,y);
      if (status == buffer_full)
	{
	  assert_false(status == buffer_full);
	}
    }

  for(uint8_t x=0; x<=7; x++)
    {
      status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
      if (status == buffer_full)
	{
	  assert_false(status == buffer_full);
	}
    }

  for(uint8_t y=1; y<=13; y++)
    {
      status = CB_buffer_add_item(&userbuff,y);
      if (status == buffer_full)
	{
	  assert_true(status == buffer_full);
	}
    }
}

/**
 *@brief Tests the buffer will fail when too many items are added
 *
 *@return Returns a test failure is too many items are added
 */
static void bufferTestOverEmpty(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;

  status = CB_buffer_remove_item(&userbuff, userbuff.poppedData);
  assert_true(status == buffer_empty);
  
}


int main(void)
{
    const struct CMUnitTest tests[] =
    {
      cmocka_unit_test(memmoveTestVoid),
      cmocka_unit_test(memmoveTestNoOverlap),
      cmocka_unit_test(memmoveTestWithOverlap),
      cmocka_unit_test(memsetTestVoid),
      cmocka_unit_test(memsetTestCheckSet),
      cmocka_unit_test(memZeroTestVoid),
      cmocka_unit_test(memZeroTestCheckSet),
      cmocka_unit_test(reverseTestVoid),
      cmocka_unit_test(reverseTestOdd),
      cmocka_unit_test(reverseTestEven),
      cmocka_unit_test(reverseTestChar),
      cmocka_unit_test(bigToLittleTestVoid),
      cmocka_unit_test(bigToLittleTestValid),
      cmocka_unit_test(littleToBigTestVoid),
      cmocka_unit_test(littleToBigTestValid),
      cmocka_unit_test(bufferAllocateTest),
      cmocka_unit_test(bufferPtrTestValid),
      cmocka_unit_test(bufferNonInitTest),
      cmocka_unit_test(bufferTestAddRemove),
      cmocka_unit_test(bufferTestFull),
      cmocka_unit_test(bufferTestEmpty),
      cmocka_unit_test(bufferTestWrapAroundADD),
      cmocka_unit_test(bufferTestWrapAroundREMOVE),
      cmocka_unit_test(bufferTestOverFill),
      cmocka_unit_test(bufferTestOverEmpty),

      };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
