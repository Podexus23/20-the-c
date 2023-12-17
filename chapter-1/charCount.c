#include <stdio.h>

int main()
{
  int c, blancCounter;
  long nl, nc, ns, nt;

  nc = 0;
  nl = 0;
  nt = 0;
  ns = 0;
  blancCounter = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      ++nt;
    }
    if (c == ' ')
    {
      ++ns;
    }
    if (c == '\b')
    {
      ++ns;
    }
    if (c == '\n')
    {
      ++nl;
    }
    if (c == ' ')
    {
      if (blancCounter == 0)
      {
        blancCounter = blancCounter + 1;
        putchar(c);
      }
    }
    if (c == '\t')
    {
      printf("\\");
      c = 't';
    }
    if (c == '\b')
    {
      printf("\\");
      c = 'b';
    }
    if (c == '\\')
    {
      printf("\\");
      c = '\\';
    }
    if (c != ' ')
    {

      putchar(c);
      ++nc;

      blancCounter = 0;
    }
  }
  printf("\nchars: %ld\n", nc);
  printf("lines: %ld\n", nl);
  printf("spaces: %ld\n", ns);
  printf("tabs: %ld\n", nt);
}