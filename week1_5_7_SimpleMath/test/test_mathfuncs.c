#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/mathfuncs.h"
#define TIMES 1000000000000



START_TEST(test_gcd_iterative)
{
  int *a = malloc(sizeof(unsigned long long int)* TIMES );
  unsigned long long int b = 0;
  while (b < TIMES) {
    if (b % 10000 == 0){
      printf("%llu\n", b);
    }
    a[b] = b;
    b++;
  }
	fail_unless(gcd_iterative(15, 20) == 5, "gcd_iterative(15, 20) should return 5");
}
END_TEST

int main(int argc, const char *argv[])
{
	Suite *s = suite_create("Test");

	tmc_register_test(s, test_sum_of_absolutes, "5.0");
	tmc_register_test(s, test_sum_of_rounded, "5.0");
	tmc_register_test(s, test_sum_of_characters, "5.0");
	tmc_register_test(s, test_gcd, "6.0");
	tmc_register_test(s, test_gcd_iterative, "7.0");

	return tmc_run_tests(argc, argv, s);
}
