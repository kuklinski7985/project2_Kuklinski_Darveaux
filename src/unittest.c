#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include "memory.c"
#include "conversion.c"
#include "circbuff.c"
#include "debug.c"

#include <setjmp.h>
#include <cmocka.h>

static void memmoveTestVoid(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = NULL;
  testsrc = NULL;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
}

static void memmoveTestNoOverlap(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = &testptrdst;
  testsrc = &testptrsrc;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
}

static void memmoveTestWithOverlap(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = &testptrdst;
  testsrc = &testptrsrc;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
}

void memsetTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_memset(testsrc,8,3) != NULL);
}

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

static void memZeroTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_memzero(testsrc,8) != NULL);
}

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

static void reverseTestVoid(void** state)
{
  uint8_t * testsrc;
  uint8_t testptrsrc;
  testsrc = NULL;
  assert_true(my_reverse(testsrc,8) != NULL);
}

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

static void bigToLittleTestVoid(void** state)
{
  uint32_t * testsrc;
  uint32_t testptrsrc;
  testsrc = NULL;
  assert_true(big_to_little32(testsrc,1) != 1);
}

static void bigToLittleTestValid(void** state)
{
  uint32_t * testsrc;
  uint32_t testData = 0xAB12CD34;
  testsrc = &testData;
  assert_true(big_to_little32(testsrc,1) == 0);
}

static void littleToBigTestVoid(void** state)
{
  uint32_t * testsrc;
  uint32_t testptrsrc;
  testsrc = NULL;
  assert_true(big_to_little32(testsrc,1) != 1);
}

static void littleToBigTestValid(void** state)
{
  uint32_t * testsrc;
  uint32_t testData = 0xAB12CD34;
  testsrc = &testData;
  assert_true(big_to_little32(testsrc,1) == 0);
}


/*************Circular Buffer Test Functions************/
static void bufferAllocateTest(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(&userbuff,length) == no_error);
}

static void bufferPtrTestValid(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(NULL,length) != null_error);
}

static void bufferNonInitTest(void** state)
{
  CB_t userbuff;
  uint8_t length = 16;
  assert_true(CB_init(&userbuff,length) == no_error);
}

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

static void bufferTestEmpty(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = CB_buffer_remove_item(&userbuff,0);
  assert_true(status == buffer_empty);
}

static void bufferTestWrapAroundADD(void** state)
{
  CB_t userbuff;
  CB_init(&userbuff,16);
  CB_status status = 0;
  uint8_t testLength = 9;
  userbuff.headptr = userbuff.circbuff + 9;  //setting headptr far enough away from source to wrpa around and not fill buffer
  for(uint8_t i=0; i<= testLength; i++)
    {
      status = CB_buffer_add_item(&userbuff,i);
    }

  assert_true(status == no_error);
}

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

      };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
