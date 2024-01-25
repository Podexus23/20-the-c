#include <stdio.h>
#include <ctype.h>

#define MAXLINE 15

int getLine(char str[], int lim);
double atof(char str[]);

int main()
{
  char line[MAXLINE];
  int length;

  length = getLine(line, MAXLINE);
  printf("number: %f\n", atof(line));
  return 0;
}

double atof(char s[])
{
  double val, power, expPower;
  int i, sign, expSign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  printf("some index: %c\n", s[i]);
  if (s[i] == 'e' || s[i] == 'E')
  {
    i++;
    if (s[i] == '+' || s[i] == '-')
    {
      expSign = (s[i] == '-') ? -1 : 1;
      i++;
    }
    else
    {
      expSign = 1;
    }

    for (expPower = 0.0; isdigit(s[i]); i++)
    {
      expPower = 10.0 * expPower + (s[i] - '0');
    }

    {
      for (; expPower > 0; expPower--)
      {
        if (expSign == -1)
        {
          power *= 10;
        }
        else
        {
          power /= 10;
        }
      }
    }
  }
  return sign * val / power;
}

int getLine(char str[], int lim)
{
  int c, i;

  i = 0;
  //--lim == (lim - 1) save 1 place for '\0'
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    str[i++] = c;
  }
  if (c == '\n')
  {
    str[i++] = c;
  }
  str[i] = '\0';

  return i;
}
