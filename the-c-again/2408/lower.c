#include <stdio.h>

char to_lower(char s);

int main(void)
{
  printf("%c", to_lower('Z'));
  return 0;
}

char to_lower(char s)
{
  return (s >= 'A' && s <= 'Z') ? s += 32 : s;
}