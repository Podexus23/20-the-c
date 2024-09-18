#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char **pnt = malloc(sizeof(char *));
  int *pnt_int = malloc(sizeof(int));
  int one = 23;
  double *onepnt = (void *)malloc(sizeof(double));
  *onepnt = 45.789;
  size_t sz_one = sizeof one;
  *pnt = "bitch";
  printf("Place: %p, str: %s\n", pnt, *pnt);
  printf("size of: %ld", sz_one);
  return 0;
}