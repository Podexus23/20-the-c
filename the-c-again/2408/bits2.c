#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getrest(unsigned x, int p);
unsigned invert(unsigned x, int p, int n);

int main(void)
{
  unsigned char tochange = 0b10011110; // 10011110 158
  tochange = invert(tochange, 5, 4);
  printf("zdarova pidrila: %d\n", tochange); // 162
  return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned invert(unsigned x, int p, int n)
{
  unsigned char leftrest, rightrest, main;
  leftrest = getrest(x, p);
  rightrest = getbits(x, p - n, p - n + 1);

  main = ~(getbits(x, p, n));
  main = getbits(main, n - 1, n) << p - n + 1;
  printf("invert: %d\n", x);
  printf("left: %d\n", leftrest);
  printf("right: %d\n", rightrest);
  printf("main: %d\n", main);
  return leftrest + main + rightrest;
}

unsigned getrest(unsigned x, int p)
{
  int res;
  res = x >> p + 1;
  return res << p + 1;
}