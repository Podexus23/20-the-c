#include <stdio.h>

#define MAXSIZE 100

int getLine(char line[], int line_length);

int main()
{
  char s1[MAXSIZE], s2[MAXSIZE];
  int lengthS1, lengthS2;
  lengthS1 = getLine(s1, MAXSIZE);
  lengthS2 = getLine(s2, MAXSIZE);

  printf("%s\n", s1);
  printf("%s\n", s2);
  squeeze(s1, s2);

  return 0;
}

int getLine(char line[], int line_length)
{
  int c;

  for (int i = 0; i < MAXSIZE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  line[i] = '\0';
  return i;
}

void squeeze(char to_delete[], char from_delete[])
{
}