#include <stdio.h>

/* print Fahrenheit-Celcius table for fahr = 0 , 20, ..., 300; */
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
  float fahr;

  printf("Fahrenheit-Celcius table\n");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  {
    printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}