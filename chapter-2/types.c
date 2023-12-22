#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("signed char min: %d", SCHAR_MIN);
  printf("signed char max: %d", SCHAR_MAX);
  printf("unsigned char: %d", UCHAR_MAX);
  printf("\n");
  printf("signed short int min: %d", SHRT_MIN);
  printf("signed short int max: %d", SHRT_MAX);
  printf("ussigned short int: %d", USHRT_MAX);
  printf("\n");
  return 0
}