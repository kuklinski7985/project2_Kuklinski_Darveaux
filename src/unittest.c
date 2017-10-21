#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include "memory.c"

#include <setjmp.h>
#include <cmocka.h>

static void memmoveTest(void** state)
{
  uint8_t * testsrc, *testdst;
  uint8_t testptrsrc, testptrdst;
  testdst = NULL;
  testsrc = NULL;
  assert_true(my_memmove(testsrc, testdst, 8) != NULL);
  }


int main(void)
{
    const struct CMUnitTest tests[] =
    {
      cmocka_unit_test(memmoveTest),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
