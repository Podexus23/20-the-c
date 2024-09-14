#include <stdio.h>

#define MAXLINE 1000

/* gcc calc.c get_line.c ato_f.c */
/* примитивный калькулятор */
int main()
{
  double sum, ato_f(char[]);
  char line[MAXLINE];
  int get_line(char line[], int max);

  sum = 0;
  while (get_line(line, MAXLINE) > 0)
    printf("\t%g\n", sum += ato_f(line));

  return 0;
}