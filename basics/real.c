/*
  Practice Project: Dynamic Array
  Write a program where the user can dynamically resize an array using pointers and realloc().
  Implement functionality to add, remove, and display elements of the array.
 */

// add commands from console
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int length = SIZE;

void print_arr(int *arr);
void add_el(int *arr, int el);
int *remove_el(int *arr, int el);

int main(int argc, char **argv)
{

  int *arr = malloc(sizeof(int) * length);
  if (!arr)
  {
    printf("Sorry not enough space for this");
    exit(1);
  }

  for (int i = 0; i < length; i++)
    arr[i] = (i + 1) * 5;

  add_el(arr, 156);
  add_el(arr, 23);
  arr = remove_el(arr, 10);

  print_arr(arr);

  return 0;
}

void print_arr(int *arr)
{
  for (int i = 0; i < length; i++)
  {
    printf("Arr[%d]: %d\n", i, arr[i]);
  }
}

void add_el(int *arr, int el)
{
  arr = realloc(arr, sizeof(int) * (++length));
  if (!arr)
  {
    printf("Sorry not enough space for this");
    exit(1);
  }
  arr[length - 1] = el;
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
      // printf("Arr i: %d", arr[i]);
      new_arr[j] = arr[i];
      // printf("Arr j: %d", arr[j]);
    }
    free(arr);
    length--;
    arr = new_arr;
  }
  return arr;
}