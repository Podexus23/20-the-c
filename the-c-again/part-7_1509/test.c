#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void print_person(char *name, int age);
void print_product(char *name, int age);

int main(int argc, char **argv)
{
  int i = 0;
  const long one = 1234;
  const long *a = &one;
  char *one_arr[] = {"tom", "dom", "bom"};

  void (*print[2])(char *, int) = {print_person, print_product};
  size_t print_len = (sizeof print) / (sizeof print[0]);
  for (i = 0; i < print_len; i++)
  {
    print[i](one_arr[i], (i + 1) * 18);
  }
  // printf("Seze: %ld\n", (sizeof(one_arr) / (sizeof(one_arr[0]))));
  // printf("Some long const: %ld\nAnd it's address: %p\n", *a, a);
}

void func_arg(int num, ...)
{

  // printf("Num: %d\n", num);
}

void print_person(char *name, int age)
{
  printf("Name: %s, Age: %d\n", name, age);
}
void print_product(char *name, int age)
{
  printf("Title: %s, Price: %d\n", name, age);
}