#include <stdio.h>

int main(void)
{
  int c, nl, tabs, np;

  // nl = tabs = np = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
}