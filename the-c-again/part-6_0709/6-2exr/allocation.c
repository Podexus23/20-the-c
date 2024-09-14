#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDSIZE 100

struct word
{
  char word[WORDSIZE];
};
struct word word_arr[10];
int counter = 0;

void print_arr_words(struct word arr[]);
void str_up(char *dest, char *from);
void sort_gr(char arr[]);

int main(int argc, char **argv)
{
  char c;
  int i = 0;
  char testword[WORDSIZE] = "zdorova";

  // while ((c = getchar()) != EOF)
  //   testword[i++] = c;

  sort_gr(testword);
  printf("Sorted: %s\n", testword);
  // char *one = &testword[1];
  // char *two = &testword[3];
  // str_up(one, two);

  printf("Str: %s\n", testword);
  // while (((c = getchar()) != EOF) && counter < 10)
  // {
  //   if (c == '\n')
  //   {
  //     char *p = word_arr[counter].word;
  //     testword[i] = '\0';
  //     strcpy(p, testword);
  //     counter++;
  //     i = 0;
  //   }
  //   testword[i++] = c;
  // }
  // print_arr_words(word_arr);
  return 0;
}

void str_up(char *dest, char *from)
{
  while (*from != '\0')
  {
    *dest++ = *from++;
  }
  *dest = '\0';
}

void print_arr_words(struct word arr[])
{
  while (counter-- > 0)
  {
    printf("%d word: %s\n", counter + 1, arr[counter].word);
  }
}

void sort_gr(char arr[])
{
  int n = strlen(arr);
  int swapped = 0;
  do
  {
    swapped = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] > arr[i])
      {
        char temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        swapped = 1;
      }
    }
  } while (swapped != 0);
}