#include <stdio.h>
#include <string.h>

// strncpy
char *strn_cpy(char *dest, char *src, int n);
// strncat
char *strn_cat(char *dest, char *src, int n);
// strncmp
int strn_cmp(char *s1, char *s2, int n);

int main(void)
{
  char one[100] = "hello";
  char two[] = "brother";

  char one1[100] = "hello";
  char two2[] = "hellowa";

  strncmp(one, two, 7);
  // strn_cat(one1, two2, 8);

  printf("After: %d\n", strn_cmp(one1, two2, 6));

  return 0;
}

char *strn_cpy(char *dest, char *src, int n)
{
  int i;
  for (i = 0; i < n && *src != '\0'; i++)
  {
    *dest++ = *src++;
  }
  if (*src == '\0')
    *dest = *src;
  return dest;
}

char *strn_cat(char *dest, char *src, int n)
{
  int i;
  while (*dest++)
    ;
  dest--;
  for (i = 0; i < n && *src != '\0'; i++)
  {
    *dest++ = *src++;
  }
  if (*src == '\0')
    *dest = *src;
  return dest;
}

int strn_cmp(char *s1, char *s2, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (*s1 == *s2)
    {
      *s1++;
      *s2++;
      continue;
    }
    else
      return *s1 - *s2;
  }

  return 0;
}