/*
  Practice Project: Dynamic Array
  Write a program where the user can dynamically resize an array using pointers and realloc().
  Implement functionality to add, remove, and display elements of the array.
 */

// add commands from console
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
int length = SIZE;

void print_arr(int *arr);
int *add_el(int *arr, int el);
int *remove_el(int *arr, int el);

int main(int argc, char **argv)
{
  int *arr = malloc(sizeof(int) * length);
  if (!arr)
  {
    printf("Sorry not enough space for this");
    exit(1);
  }
  char comm[100] = "start";
  int el;

  for (int i = 0; i < length; i++)
    arr[i] = (i + 1) * 5;

  do
  {
    printf("add, remove or print array\n");
    printf("to close programm write end command\n");
    scanf("%s %d", comm, &el);
    if (strcmp(comm, "add") == 0)
      arr = add_el(arr, el);
    if (strcmp(comm, "pr") == 0)
      print_arr(arr);
    if (strcmp(comm, "rm") == 0)
      arr = remove_el(arr, el);

  } while (strcmp(comm, "end") != 0);

  // add_el(arr, 23);
  //

  // print_arr(arr);

  return 0;
}

void print_arr(int *arr)
{
  for (int i = 0; i < length; i++)
    printf(" %d |", arr[i]);
  // printf("Arr[%d]: %d\n", i, arr[i]);

  printf("\n");
}

int *add_el(int *arr, int el)
{
  arr = realloc(arr, sizeof(int) * (++length));
  if (!arr)
  {
    printf("Sorry not enough space for this");
    exit(1);
  }
  arr[length - 1] = el;
  return arr;
}

int *remove_el(int *arr, int el)
{
  int n = -1;
  for (int i = 0; i < length; i++)
  {
    if (arr[i] == el)
      n = i;
  }
  if (n < 0)
    printf("Sorry no such element in an array");
  else
  {
    int *new_arr = malloc(sizeof(int) * (length - 1));
    for (int i = 0, j = 0; i < length; i++, j++)
    {
      if (i == n)
        i++;
      new_arr[j] = arr[i];
    }
    free(arr);
    length--;
    arr = new_arr;
  }
  return arr;
}