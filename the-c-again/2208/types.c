#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
  int a;
  printf("limits.h\n");
  printf("%d\n", CHAR_BIT);
  printf("%d\n", CHAR_MAX);
  printf("%d\n", CHAR_MIN);
  printf("%d\n", INT_MAX);
  printf("%d\n", INT_MIN);
  printf("%ld\n", LONG_MAX);
  printf("%ld\n", LONG_MIN);
  printf("%d\n", SCHAR_MAX);
  printf("%d\n", SCHAR_MIN);
  printf("%d\n", SHRT_MAX);
  printf("%d\n", SHRT_MIN);
  printf("%d\n", UCHAR_MAX);
  printf("%d\n", UINT_MAX);
  printf("%ld\n", ULONG_MAX);
  printf("%d\n", USHRT_MAX);
  printf("float.h\n");
  printf("%d\n", FLT_RADIX);
  printf("%d\n", FLT_ROUNDS);
  printf("%d\n", FLT_DIG);
  printf("%f\n", FLT_EPSILON);
  printf("%d\n", FLT_MANT_DIG);
  printf("%f\n", FLT_MAX);
  printf("%d\n", FLT_MAX_EXP);
  printf("%f\n", FLT_MIN);
  printf("%d\n", FLT_MIN_EXP);
  printf("%d\n", DBL_DIG);
  printf("%e\n", DBL_EPSILON);
  printf("%d\n", DBL_MANT_DIG);
  printf("%e\n", DBL_MAX);
  printf("%d\n", DBL_MAX_EXP);
  printf("%e\n", DBL_MIN);
  printf("%d\n", DBL_MIN_EXP);
  return 0;
}