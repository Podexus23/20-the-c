#include <stdio.h>

#define LOWER 0   /* нижний предел диапазона */
#define UPPER 300 /* верхний предел диапазона */
#define STEP 20   /* разммер шага */

int fahr_to_celcius_func(int s, int e);

int main(void)
{
  fahr_to_celcius_func(LOWER, 200);
}

int celcius_to_fahr(void)
{
  float fahr, celcius;
  int lower, upper, step;

  lower = LOWER; /* нижняя граница */
  upper = 100;   /*верхняя граница*/
  step = 10;     /*величина шага*/

  celcius = lower; /* 0 */

  printf("это заголовок над таблицей\n");
  while (celcius <= upper)
  {
    fahr = 32.0 + 9.0 / 5.0 * celcius;
    printf("%3.0f %4.1f\n", celcius, fahr);
    celcius = celcius + step;
  }
}

int fahr_to_celcius_func(int start, int end)
{
  float fahr, celcius;

  fahr = start; /* 0 */

  printf("это заголовок над таблицей\n");
  while (fahr <= end)
  {
    celcius = 5.0 * (fahr - 32.0) / 9.0;
    printf("%3.0f %4.1f\n", fahr, celcius);
    fahr = fahr + STEP;
  }
}

int fahr_to_celcius(void)
{
  float fahr, celcius;
  // int lower, upper, step;

  // lower = 0; /* нижняя граница */
  // upper = 300;   /*верхняя граница*/
  // step = 20;     /*величина шага*/

  fahr = LOWER; /* 0 */

  printf("это заголовок над таблицей\n");
  while (fahr <= UPPER)
  {
    celcius = 5.0 * (fahr - 32.0) / 9.0;
    printf("%3.0f %4.1f\n", fahr, celcius);
    fahr = fahr + STEP;
  }
}
