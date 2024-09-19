#include <stdio.h>

int main(int argc, char *argv[])
{
  float one;
  float two;
  char op;

  printf("please write your numbers and operation to perform as in example: 2 + 2\n");
  scanf("%g %c %g", &one, &op, &two);

  switch (op)
  {
  case '+':
    printf("Result: %g\n", one + two);
    break;
  case '-':
    printf("Result: %g\n", one - two);
    break;
  case '*':
    printf("Result: %g\n", one * two);
    break;
  case '/':
    printf("Result: %g\n", one / two);
    break;
  default:
    printf("calc: sorry, wrong operation, please try again");
    break;
  }
  return 0;
}