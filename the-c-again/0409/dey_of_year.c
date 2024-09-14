#include <stdio.h>

int day_of_year(int year, int month, int day);

static char day_norm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char day_leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[2] = {day_norm, day_leap};

int main(void)
{
  printf("Day of the Year: %d\n", day_of_year(1992, 2, 13));
  return 0;
}

/* day of year: вычисления дня года по месяцу и дню*/
int day_of_year(int year, int month, int day)
{
  int i, leap;

  if (month > 12 || day > 31)
    printf("Error: wrong range of days or month: %d || %d\n", day, month);

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; i++)
  {
    day += daytab[leap][i];
  }
  return day;
}

/* month day: вычисление месяца и даты по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  if (yearday > 365)
    printf("Error: wrong range of days for 1 year: %d\n", yearday);

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}