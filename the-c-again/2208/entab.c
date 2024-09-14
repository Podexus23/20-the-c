#include <stdio.h>

#define SPACES 4

int main(void)
{

  int c, i;
  int counter;
  int tabs, sp;

  counter = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      ++counter;
    else if (c != ' ' && counter != 0)
    {
      tabs = counter / SPACES;
      sp = counter - tabs * SPACES;
      if (tabs > 0)
      {
        for (i = 0; i < tabs; ++i)
          putchar('t');
      }
      for (i = 0; i < sp; ++i)
        putchar('s');
      counter = 0;
      putchar(c);
    }
    else
      putchar(c);
  }
  return 0;
}