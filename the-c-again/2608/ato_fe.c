#include <ctype.h>
#include <stdio.h>

double expo(char s[]); /* преобразование экспоненты в конце строки в числовой аргумент */
double ato_f(char s[]);

/* atof: преобразование строки s в число тgccипа double */
double ato_f(char s[])
{
  double val, power;
  int i, sign;
  double ex = 1.0;

  for (i = 0; isspace(s[i]); i++) /* пропуск пробелов */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  if (s[i] == 'e' || s[i] == 'E')
  {
    ex = expo(s);
  }

  return sign * val / power * ex;
}

double expo(char s[])
{
  int i, j, sign, val;
  double ex = 1.0;

  for (i = 0; s[i] != 'e' && s[i] != 'E'; i++) /* пропуск чисел до Е */
    ;
  i++;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  for (j = 0; j < val; j++)
    (sign > 0) ? (ex *= 10) : (ex /= 10);

  return ex;
}