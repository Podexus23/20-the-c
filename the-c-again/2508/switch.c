#include <stdio.h>

#define ARR_SIZE 100

int char_counter(void);
void escape(char s[], char t[]);
void revert_escape(char s[], char t[]);

int main(void)
{

  char one[ARR_SIZE] = "eto one \\n privet \\t loshok";
  char two[ARR_SIZE] = "eto two";

  revert_escape(one, two);
  printf("changed two: %s\n", two);
  return 0;
}

void revert_escape(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while ((t[j] = s[i]) != '\0')
  {
    if (s[i] == '\\')
      switch (s[i + 1])
      {
      case 'n':
        t[j] = '\n';
        i++;
        break;
      case 't':
        t[j] = '\t';
        i++;
        break;
      }
    i++;
    j++;
  }
}

void escape(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while ((t[j] = s[i]) != '\0')
  {
    switch (s[i])
    {
    case '\n':
      t[j++] = '\\';
      t[j] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j] = 't';
      break;

      i++;
      j++;
    }
    i++;
    j++;
  }
}

int char_counter(void)
{
  int c, i, nwhite, nother, ndigit[10];

  nwhite = nother = 10;
  for (i = 0; i < 10; i++)
  {
    ndigit[i];
  }

  while ((c = getchar()) != EOF)
  {
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      ndigit[c - '0']++;
      break;
    case ' ':
    case '\n':
    case '\t':
      nwhite++;
      break;

    default:
      nother++;
      break;
    }
  }
  printf("digits =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);
  return 0;
}
