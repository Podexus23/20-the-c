#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(long int n, char s[], int wh);
void itob(long int n, char s[], int size);
void ito16(long int n, char s[]);
void ito8(long int n, char s[]);
void ito2(long int n, char s[]);
void reverse(char s[]);
void add_white(char s[], int spc);
/*
  разобраться как происходит преобразовывание из десятичного в шестнадцати, восьми и двоичную систмему
  при входе в функцию в зависимости от режима сразу переходи либо туда либо сюда

  из реально сложного, это буквы в шестнадцатиричной
  и отрицательные значения в двоичной
*/

int main(void)
{
  long int b = 375;
  char str[100];

  // printf("longest %ld\n", LONG_MAX + 1);
  itob(b, str, 2);
  printf("long %ld\n", b);
  printf("str %s\n", str);
  return 0;
}

void itob(long int n, char s[], int size)
{
  if (size == 10)
    itoa(n, s, 10);
  if (size == 16)
    ito16(n, s);
  if (size == 8)
    ito8(n, s);
  if (size == 2)
    ito2(n, s);
}

void ito2(long int n, char s[])
{
  long int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do
  {
    s[i++] = n % 2 + '0';
  } while ((n /= 2) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void ito8(long int n, char s[])
{
  long int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do
  {
    s[i++] = n % 8 + '0';
  } while ((n /= 8) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void ito16(long int n, char s[])
{
  long int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do
  {
    if (n % 16 < 10)
      s[i++] = n % 16 + '0';
    else
    {
      switch (n % 16)
      {
      case 10:
        s[i++] = 'A';
        break;
      case 11:
        s[i++] = 'B';
        break;
      case 12:
        s[i++] = 'C';
        break;
      case 13:
        s[i++] = 'D';
        break;
      case 14:
        s[i++] = 'E';
        break;
      case 15:
        s[i++] = 'F';
        break;

      default:
        break;
      }
    }
  } while ((n /= 16) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void itoa(long int n, char s[], int wh)
{
  long int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do
  {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  add_white(s, wh);
  reverse(s);
}

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void add_white(char s[], int spc)
{
  int i;
  int size = strlen(s);

  if (spc > size)
  {
    for (i = size; i <= spc; i++)
      s[i] = ' ';

    s[i] = '\0';
  }
}