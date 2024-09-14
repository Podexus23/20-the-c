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

int comm_check(char s[], char t[]);
int str_len(char s[]);
double top(void);
void copy(void);
void swap(void);
void clean_stack(void);
void get_all_stack(void);

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

int do_comm(char s[])
{
  // if (str_len(s) == 1)
  //   return ARG;
  if (comm_check(s, "copy"))
    copy();

  else if (comm_check(s, "top"))
    top();

  else if (comm_check(s, "swap"))
    swap();

  else if (comm_check(s, "clean"))
    clean_stack();

  else if (comm_check(s, "sin"))
    return SIN;
  else if (comm_check(s, "exp"))
    return EXP;
  else if (comm_check(s, "pow"))
    return POW;
  // else if (comm_check(s, "var"))
  //   return VAR;

  get_all_stack();
  return 0;
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