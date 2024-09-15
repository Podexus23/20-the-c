#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
  int i = 0;
  char def = argv[0][i];
  char c;

  while (!isalpha(def))
    def = argv[0][i++];
  if (def >= 'A' && def <= 'Z')
  {
    printf("hi");
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
  }
  else if (def >= 'a' && def <= 'z')
  {
    printf("hi");
    while ((c = getchar()) != EOF)
      putchar(toupper(c));
  }
  return 0;
}