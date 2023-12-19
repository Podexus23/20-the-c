#include <stdio.h>
#define MAXLINE 20 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// делаем ещё один запасной массив
//  если длина строки больше него, пишем сообщение что строка слишком длинная для вывода целиком, но вот длинна её вот такая

/* print longest input line */
int main()
{
  int maxlineNum;
  maxlineNum = MAXLINE;

  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
  {
    printf("%s", longest);
    // printf('Line is too long to copy, the limit is:');

    printf("\n");                      /* there was a line */
    printf("line length: %d \n", max); /* there was a line */
  }
  return 0;
}

/* getline: read a line into a s, return length */
int getLine(char s[], int lim)
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

  while ((c = getchar()) != EOF && c != '\n')
    ++i;

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}