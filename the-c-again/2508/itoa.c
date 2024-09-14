#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(long int n, char s[], int wh);
void reverse(char s[]);
void add_white(char s[], int spc);

int main(void)
{
  // long int a = LONG_MIN;
  long int b = -1231123;
  char str[100];

  itoa(b, str, 8);
  printf("long %ld\n", b);
  printf("str %s\n", str);
  return 0;
}

void itoa(long int n, char s[], int wh)
{
  long int i, sign;

  if ((sign = n) < 0)
    n = ((n + 1) * -1);
  i = 0;
  do
  {
    if (i == 0 && sign < 0)
      s[i++] = n % 10 + '0' + 1;
    else
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
  int i, j;
  int size = strlen(s);

  if (spc > size)
    for (i = size; i <= spc; i++)
      s[i] = ' ';

  s[i] = '\0';
}