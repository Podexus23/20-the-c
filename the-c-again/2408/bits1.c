#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getrest(unsigned x, int p);

int main(void)
{
  //   unsigned char tochange = 0b10111011; // 10111011 187
  //   unsigned char res = 0b01010010;      // 01010010
  unsigned char tochange = 0b10011110; // 10011110 158
  unsigned char res = 0b10000010;      // 10000010
  res = setbits(tochange, 6, 4, res);  // 10010110 150
  printf("zdarova pidrila: %d\n", res);
  return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned char tomove = getbits(y, n - 1, n); //+ 0000 0010
  unsigned char rest = getrest(x, p);

  printf("ne pidrila rest:%d\n", rest);
  printf("ne pidrila:%d\n", tomove);
  printf("tomove %d\n", getbits(x, p, n));
  return (x & ~(~tomove << p + 1 - n)) + rest;
}

unsigned getrest(unsigned x, int p)
{
  int res;
  res = x >> p + 1;

  return res << p + 1;
}