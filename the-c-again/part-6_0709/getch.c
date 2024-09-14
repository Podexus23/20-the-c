#include <stdio.h>
#include <string.h>

#define BUFSIZE 100 /* размер буфера */
enum math_op
{
  SIN = 1,
  EXP,
  POW,
  VAR,
  ARG
};

char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0;      /* следующая свободная позиция в buf */

int comm_char(char s[], char t[]);
int str_len(char s[]);

int getch(void) /* ввод символа, возможно возвращенного в поток */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

int ungetch(int c) /* возвращение символа в поток */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int comm_check(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while ((s[i] == t[i]) && s[i] != '\0' && s[i] != '\n')
    i++;

  return i == str_len(s) ? 1 : 0;
}

int str_len(char s[])
{
  int i;
  for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i)
    ;
  return i;
}