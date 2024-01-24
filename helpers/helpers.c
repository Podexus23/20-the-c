#include <stdio.h>

#define MAXLINE 10

int getLine(char str[], int lim);

int main()
{
  char line[MAXLINE];
  int length;

  length = getLine(line, MAXLINE);
  printf("line: %s", line);
  printf("line length: %d", length);
  printf("line unown %d", line[8]);
  return 0;
}

int getLine(char str[], int lim)
{
  int c, i;

  i = 0;
  //--lim == (lim - 1) save 1 place for '\0'
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    str[i++] = c;
  }
  if (c == '\n')
  {
    str[i++] = c;
  }
  str[i] = '\0';

  return i;
}