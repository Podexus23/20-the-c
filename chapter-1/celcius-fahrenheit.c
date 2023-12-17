#include <stdio.h>

/* print Celcius-Fahrenheit table for fahr = 0 , 20, ..., 300; */

int main()
{
  float fahr, celcius;
  int lower, upper, step;

  lower = -50;
  upper = 150;
  step = 10;

  celcius = lower;
  printf("Celcius-Fahrenheit table\n");
  while (celcius <= upper)
  {
    fahr = celcius * (9.0 / 5.0) + 32.0;
    printf("%3.0f %6.0f\n", celcius, fahr);
    celcius = celcius + step;
  }
}