/* заменяет в потоке символы табуляции на n колчиство пробелов */
#include <stdio.h>

#define SPACES 4 /* колчиствео пробелов */

int main(void)
{
  int c, i;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      for (i = 0; i < SPACES; ++i)
      {
        putchar(' ');
      }
    }
    else
      putchar(c);
  }

  return 0;
}