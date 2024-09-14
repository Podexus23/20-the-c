#include <stdio.h>

#define MAXSIZE 15
char res[15];

void squeeze(char s[], int c);

int main()
{
  extern char res[];

  char one[15] = "passos biba";
  char dva[15] = "pisos";

  int i;

  for (i = 0; dva[i] != '\0'; i++)
  {
    squeeze(one, dva[i]);
  }

  printf("%s\n", one);
  return 0;
}

void squeeze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i)
  {
    if (s[i] != c)
    {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}