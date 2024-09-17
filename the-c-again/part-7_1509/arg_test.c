#include <stdio.h>
#include <stdarg.h>

void some_func(int, int, ...);

int main(int argc, char **argv)
{
  some_func(5, 12, 123, 441);
  return 0;
}

void some_func(int frst, int sec, ...)
{
  int i = 0;
  va_list hui;
  va_start(hui, frst);

  for (i = 0; i < 10; i++)
  {
    printf("va_arg: %p\n", hui);
    printf("argumentiki: %d\n", va_arg(hui, int));
  }
  printf("Poehali: %d\n", frst);
  printf("Poehali: %d\n", sec);
}