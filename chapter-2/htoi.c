#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 100

char line[MAXSIZE];
int line_length;

int getLine();
int htoi();

int main()
{
  int line;
  char strArr[100];

  while ((line = getLine()) > 0)
  {
    htoi();
  }
  return 0;
}

int getLine()
{
  extern char line[];
  extern int line_length;

  int c, i;

  for (i = 0; i < MAXSIZE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  line[i] = '\0';
  line_length = i;

  return i;
}

int htoi()
{
  extern char line[];
  extern int line_length;

  int ichar;
  int summ;

  summ = 0;
  for (int i = 0; i < line_length; ++i)
  {
    ichar = line[i];
    if (ichar >= 'a' && ichar <= 'z')
    {
      line[i] = toupper(line[i]);
      ichar = line[i];
    }
    // count summ
    if (ichar >= 'A' && ichar <= 'Z')
    {
      summ += (ichar - 55) * pow(16, line_length - i - 1);
    }
    else
    {
      summ += (ichar - 48) * pow(16, line_length - i - 1);
    }
  }
  printf("summ = %d\n", summ);
  return summ;
}