#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("signed char min: %d \n", SCHAR_MIN);
  printf("signed char max: %d \n", SCHAR_MAX);
  printf("unsigned char: %d \n", UCHAR_MAX);
  printf("\n");
  printf("signed short int min: %d \n", SHRT_MIN);
  printf("signed short int max: %d \n", SHRT_MAX);
  printf("ussigned short int: %d \n", USHRT_MAX);
  printf("\n");
  return 0;
}