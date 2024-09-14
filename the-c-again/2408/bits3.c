#include <stdio.h>

int get_bitssize(unsigned x);
unsigned rightrot(unsigned x, int n);

int main(void)
{
  unsigned char tochange = 0b10011110; // 11101001 233

  printf("size %d\n", rightrot(tochange, 4));

  return 0;
}

int get_bitssize(unsigned x)
{
  int i;
  for (i = 0; (x >> i) >= 1; ++i)
    ;

  return i;
}

unsigned rightrot(unsigned x, int n)
{
  int size = get_bitssize(x);
  unsigned ex;
  int i, true;
  for (i = 0; i < n; ++i)
  {
    true = 1 & x;
    if (true)
    {
      ex = 1 << size - 1;
      x = (x >> 1) + ex;
    }
    else
    {
      x >>= 1;
    }
  }
  return x;
}