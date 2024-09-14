#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(long int n, char s[], int i);
void reverse(char s[], int len);
// void add_white(char s[], int spc);

int main(void)
{
  // long int a = LONG_MIN;
  long int b = -1231123;
  char str[100];

  itoa(b, str, 0);
  printf("long %ld\n", b);
  printf("str %s\n", str);
  return 0;
}

// void itoa(long int n, char s[])
// {
//   long int i, sign;

//   if ((sign = n) < 0)
//     n = -n;
//   i = 0;

//   do
//   {
//     s[i++] = n % 10 + '0';
//   } while ((n /= 10) > 0);

//   if (sign < 0)
//     s[i++] = '-';
//   s[i] = '\0';
//   reverse(s, strlen(s) - 1);
// }

void itoa(long int n, char s[], int i)
{
  long int sign;

  if ((sign = n) < 0)
    n = -n;

  if (!((n / 10) != 0))
  {
    s[i++] = n % 10 + '0';
    if (sign < 0)
      s[i++] = '-';
    s[i] = '\0';
    reverse(s, strlen(s) - 1);
    return;
  }
  else
  {
    s[i] = n % 10 + '0';
    if (sign < 0)
      n *= -1;
    itoa(n / 10, s, i + 1);
  }
}

void reverse(char s[], int len)
{
  int c, i;
  i = strlen(s) - len - 1;
  if (len <= i)
    return;
  else
  {
    c = s[i];
    s[i] = s[len];
    s[len] = c;
    reverse(s, len - 1);
  }
}
