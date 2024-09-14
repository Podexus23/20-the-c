#include <stdio.h>

void *strcat(char *f, char *t);
int strend(char *f, char *t);

int main(void)
{
  char one[100] = "hello";
  char boba[100] = "hello bro";
  char two[100] = " bro";

  // strcat(one, two);
  // strend(one, two);
  printf("%d\n", strend(boba, two));

  return 0;
}

void *strcat(char *f, char *t)
{
  while (*f++ != '\0')
    ;
  f--;
  while (*t != '\0')
  {
    *f++ = *t++;
  }
  *f = '\0';
}

int strend(char *f, char *t)
{
  char *end = t;
  while (*f++ != '\0')
    ;
  while (*t++ != '\0')
    ;
  while ((*t-- == *f--) && t != end)
  {
    if (*t != *f)
      return 0;
  }
  *f = '\0';
  return 1;
}