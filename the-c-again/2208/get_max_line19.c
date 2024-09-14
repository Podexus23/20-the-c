#include <stdio.h>
#define MAXLINE 100 /* максимальная длина строки в потоке*/

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char to[], char from[], int len);

int main()
{
  int len;               /* длина текущей строки */
  int max;               /* текущая максимальная длина */
  char line[MAXLINE];    /* текущая введенная строка */
  char longest[MAXLINE]; /* самая длинная строка из ввдененных*/

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
  {
    reverse(longest, line, len);
    printf("%s\n", longest);
  }
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
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