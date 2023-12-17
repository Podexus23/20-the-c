#include <stdio.h>

int main()
{
  int c;

  while (c = (getchar() != EOF))
  {
    printf("%d EOF result\n", EOF);
    printf("%d comparng getchar() != EOF result\n", c);
    putchar(c);
  }
}