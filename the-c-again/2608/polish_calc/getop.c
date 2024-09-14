#include <ctype.h>
#include <stdio.h>

#define NUMBER '0' /* сигнал, что обнаружено число */
#define COMM '1'   /* сигнал, что обнаружена комманда */

int getch(void);
void ungetch(int);

/* getop: извлекает следующий операнд или знак операции */
int getop(char s[])
{
  int i, c;
  i = 0;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (isalpha(c)) /* проверка на буквы */
  {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    return COMM;
  }

  if (!isdigit(c) && c != '.')
  {
    if (s[0] == '-') /* проверка отрицательных чисел */
    {
      char temp = c = getch();
      if (isdigit(temp))
      {
        s[1] = temp;
        i += 2;
      }
      else
      {
        ungetch(c);
        return s[0];
      }
    }
    else
      return c; /* не число */
  }

  if (isdigit(c)) /* накомпление целой части*/
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* накопление дробной части*/
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}