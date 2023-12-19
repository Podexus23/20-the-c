#include <stdio.h>

#define POS_LENGTH 20
#define MAXLINE 100;

int check_line();
int getLine();
void copy();

int main()
{
  int i, c;                      /* iterator and chracter catcher*/
  int line;                      /* line length */
  int strArr[100], copyArr[100]; /* arr to check, and arr to print if condition satisfied*/

  while ((line = getLine(strArr, MAXLINE) > 0))
  {
    if (line > POS_LENGTH)
    {
      printf("%s", strArr);
    }
    else
    {
      printf("\n");
    }
  }
  return 0;
}

int getLine(char arr[], lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    arr[i] = c;
  }
  if (c = '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}