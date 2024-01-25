#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
// double atof(char s[]);
// int getLine(char s[], int lim);

int main()
{
  double sum, atof(char[]);
  char line[MAXLINE];
  int getLine(char line[], int max);

  sum = 0;
  while (getLine(line, MAXLINE) > 0)
  {
    printf("\t%g\n", sum += atof(line));
  }
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

// int atoi(char s[])
// {
//   double atof(char s[]);

//   return (int)atof(s);
// }