/* 17 программа для вывода всех строк длинной больше заданной */

/* вести какой то счетчик или просто проверять если, больше 10 - то выводим, если нет то в нибытие
  пишем в массив всё что заходит, если строка меньше 10 символов, чистим массив, следим за слудующей строкой

*/

#include <stdio.h>
#define MAXLINE 100 /* максимальная длина строки в потоке*/
#define LIMIT 10    /* максимальная длина строки в потоке*/

int get_line(char line[], int maxline);

int get_line2(char line[], int maxline); /* тот же функционал, но длину выхоядищую за рамки массива */
void copy(char to[], char from[]);

int main()
{
  int i;
  int len;               /* длина текущей строки */
  int max;               /* текущая максимальная длина */
  char line[MAXLINE];    /* текущая введенная строка */
  char longest[MAXLINE]; /* самая длинная строка из ввдененных*/

  max = 0;
  while ((len = get_line2(line, MAXLINE)) > 0)
  {
    if (len >= LIMIT)
    {
      max = len;
      copy(longest, line);
      printf("%s", longest);
      printf("String length: %d\n", max);
      for (i = 0; i < MAXLINE; ++i)
      {
        line[i] = 0;
        longest[i] = 0;
      }
    }
  }
  return 0;
}

int get_line2(char s[], int lim)
{
  int c, i, j;
  j = 0;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
    j = i + 1;
  }
  if (i >= lim - 1 && c != '\n' && c != EOF)
  {
    for (; (c = getchar()) != EOF && c != '\n'; ++j)
      ;
  }
  else if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return j;
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