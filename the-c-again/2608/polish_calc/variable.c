/*
  однобуквенные в низком регистре
*/
#include <stdio.h>

#define VARSTACK_SIZE 50

static char var[VARSTACK_SIZE];
static double var_def[VARSTACK_SIZE];

int il = 0; /* индекс последнего даобавленного значения*/
int is = 0; /* индекс для поиска значений по переменной */

int search_arg(char s);

int do_var(char s[])
{
  printf("hi var");
  return 0;
}

char do_arg(char s[])
{
  if (il < VARSTACK_SIZE)
  {
    int index = search_arg(s[0]);
    if (index > 0)
      printf("arg: already in stack\n");
    else
      var[il++] = s[0];
  }
};

int search_arg(char s)
{
  int i = 0;
  for (; i < il; i++)
    if (s == var[i])
    {
      is = i;
      return i;
    }
    else
      return -1;
}