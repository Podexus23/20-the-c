#include <stdio.h>

#define ARR_SIZE 1000

void expand(char s[], char t[]);

int main(void)
{
  char one[ARR_SIZE] = "some text    -a-g-m-0-9    A-A bla"; // a-b-c a-z0-9 -a-b!
  char two[ARR_SIZE] = "eto two";

  expand(one, two);
  printf("first one: %s\n", one);
  printf("first two: %s\n", two);
  return 0;
  return 0;
}

void expand(char s[], char t[])
{
  int i, j;
  int size;

  /*
  сделать проверку что бы левая часть была ниже чем правая

  сделать прорвеку на символы
    т.е. если слева цифра справа тоже цифра
    если слева низкий регистр то справа тоже низкий регистр
   */

  i = j = 0;
  while ((t[j] = s[i]) != '\0')
  {
    if (s[i] == '-' && i > 1 && i < ARR_SIZE - 1)
    {
      int left = s[i - 1];
      int right = s[i + 1];
      // printf("left: %d, right: %d\n", left, right);
      if ((left >= 'a' && right <= 'z') && (right - left > 0))
      {
        for (size = 1; size <= right - left; ++size)
          t[j++] = left + size;

        i++;
        j--;
      }
      if ((left >= 'A' && right <= 'Z') && (right - left > 0))
      {
        for (size = 1; size <= right - left; ++size)
          t[j++] = left + size;

        i++;
        j--;
      }
      if ((left >= '0' && right <= '9') && (right - left > 0))
      {
        for (size = 1; size <= right - left; ++size)
          t[j++] = left + size;

        i++;
        j--;
      }
    }
    // printf("%c", s[i]);
    i++;
    j++;
  }
}