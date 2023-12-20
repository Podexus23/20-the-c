#include <stdio.h>

#define MAXLINE 20

int getLine(char arr[], int maxline);
void reverse_line(char dir[], char rev[], int lim);

int main()
{
  int i, c;                          /* iterator and chracter catcher*/
  int line;                          /* line length */
  char strArr[100], reverseArr[100]; /* arr to check, and arr to print if condition satisfied*/

  while ((line = getLine(strArr, MAXLINE)) > 0)
  {
    reverse_line(strArr, reverseArr, line);
    printf("%s \n", reverseArr);
  }
  return 0;
}

int getLine(char arr[], int lim)
{
  int c, i;
  int blank;

  blank = 0;
  for (i = 0; i < lim - 1; ++i)
    arr[i] = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    if (c == ' ' || c == '\t')
    {
      blank = 1;
      --i;
    }
    else if (blank == 1 && (c != ' ' || c != '\t'))
    {
      arr[i] = ' ';
      ++i;
      arr[i] = c;
      blank = 0;
    }
    else if (blank == 0)
      arr[i] = c;
  }
  arr[i] = '\0';
  return i;
}

void reverse_line(char dir[], char rev[], int lim)
{
  for (int i = lim - 1; i >= 0; --i)
  {
    rev[lim - i] = dir[i];
  }
};