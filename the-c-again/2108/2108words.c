#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* снаружи слова */

/* подсчет строк, слов, символов в одном потоке*/
int main(void)
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
    if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
    {
      state = OUT;
      printf("\n");
    }
    else if (state == OUT && c != ' ')
    {
      state = IN;
      ++nw;
      putchar(c);
    }
    else if (state == IN)
    {
      putchar(c);
    }
  }
}

int words_lines_chars_counter(void)
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }

  printf("Lines:%d, word:%d, chars:%d\n", nl, nw, nc);
}