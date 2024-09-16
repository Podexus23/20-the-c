#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  const long one = 1234;
  const long *a = &one;
  char *one_arr[] = {"tom", "dom", "bom"};

  printf("Seze: %ld\n", (sizeof(one_arr) / (sizeof(one_arr[0]))));

  // printf("Some long const: %ld\nAnd it's address: %p\n", *a, a);
}

void func_arg(int num, ...)
{

  // printf("Num: %d\n", num);
}