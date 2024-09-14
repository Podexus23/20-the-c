#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "a"; /* образец для поиска */

/* поиск всех строк содерожащих образец */
int main(void)
{
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0)
  {
    printf("%d\n", strrindex(line, pattern));
  }
  return 0;
}

/* get_line: считывает строку в s, возвращает её длину */
int get_line(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: возвращает индекс строки t в s, -1 при отсутствии */
int strindex(char s[], char t[])
{
  int i, j, k;
  for (i = 0; s[i] != '\0'; ++i)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}

/* самый правый индекс вхождения строки t в s*/
int strrindex(char s[], char t[])
{
  int i, j, k;
  int last_i = -1;

  for (i = 0; s[i] != '\0'; ++i)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      last_i = i;
  }
  return last_i;
}