#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
  int c[10];
  int i;
  for (i = 0; i < 10; ++i)
  {
    c[i] = i;
  }

  printf("%d\n", binsearch(9, c, 10));

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
  }
  if (mid)
    return mid;
  else
    return -1;
}