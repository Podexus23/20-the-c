#include <stdio.h>
#define MAXLINE 100 /* максимальная длина строки в потоке*/

int max;
char line[MAXLINE];    /* текущая максимальная длина */
char longest[MAXLINE]; /* самая длинная строка из ввдененных*/

int get_line(void);
void copy(void);

void reverse(char to[], char from[], int len);

int main()
{
  int len; /* длина текущей строки */
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
  {
    if (len > max)
    {
      max = len;
      copy();
    }
  }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int get_line(void)
{
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy()
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
  {
    ++i;
  }
}

void reverse(char to[], char from[], int len)
{
  int i;

  i = 0;
  printf("%d", from[len - i]);
  while (len - 1 - i >= 0)
  {
    to[0 + i] = from[len - 1 - i];
    ++i;
  }
  to[i] = '\0';
}