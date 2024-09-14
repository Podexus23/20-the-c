/* 18 удаление лишних пробелов и табуляций в хвосте каждой строки входного потока */

/* засекаем пробел координатой
смотрим сколько раз повторяется
если после повторов есть перенос, возвращаемся к координате и с того места удаляем пробелы
если нет переноса, снова следим за происходящим
*/

#include <stdio.h>
#define MAXLINE 100 /* максимальная длина строки в потоке*/

int get_line(char s[], int lim);
void copy_fix(char to[], char from[]);

int main()
{
  int i;
  int len;             /* длина строки для проверки воода строк */
  char line[MAXLINE];  /* изначалный массив ввода строки */
  char fixed[MAXLINE]; /* массив для строки без пробелов и табуляций в конце */

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    copy_fix(fixed, line);
    printf("Line:%s|\n", line);
    printf("Fixed line:%s|\n", fixed);
    for (i = 0; i < MAXLINE; ++i)
    {
      line[i] = 0;
      fixed[i] = 0;
    }
  }
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

void copy_fix(char to[], char from[])
{
  int i, j;
  int st, fn;

  i = st = fn = 0;
  while ((to[i] = from[i]) != '\0')
  {
    if (to[i] == ' ' || to[i] == '\t')
    {
      if (st == 0)
      {
        st = i;
        ++fn;
      }
      else
        ++fn;
    }
    else
    {
      st = 0;
      fn = 0;
    }

    ++i;
  }
  printf("%d\n", to[i - 1]);
  if (st != 0 && to[i] == '\0')
  {
    to[st] = '\n';
    to[st] = '\0';
  }
  printf("Start:%d, cuantity: %d\n", st, fn);
}