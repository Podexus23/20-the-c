/*
  Stage 3: Arrays and Strings
    Topics:
      Arrays:
        Declaration, initialization, and usage of arrays
        Multi-dimensional arrays
      Strings:
        Introduction to strings (char[])
        String manipulation using library functions (strlen(), strcpy(), strcmp())
    Practice Project: Sorting Algorithm Implementation
        Write a program to implement and compare sorting algorithms like bubble sort and selection sort.
        Allow the user to input an array of numbers and display the sorted output.
*/

/*
  create array with random nubers
  create sort algorithms
  sort arrays and mesure them by time and by compariosns and swaps
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gnrt_int_arr(int arr[], int, int, int);
int bubble_sort_1(int arr[], int len);
int selected_sort(int *a, int len);
void swap(int *a, int *b);

#define SIZE 20000

int main()
{
  int c = 0;
  int arr[SIZE];
  gnrt_int_arr(arr, 0, 100, SIZE);
  int copy_arr[SIZE];
  // int copy_arr_2[SIZE] = {10, 9, 5, 7, 0, 5, 4, 3, 2, 1};
  int compare, compare_1;

  while (c != SIZE)
  {
    copy_arr[c] = arr[c];
    c++;
  }

  clock_t start = clock();
  compare = bubble_sort_1(arr, SIZE);
  clock_t end = clock();

  clock_t start_1 = clock();
  compare_1 = selected_sort(copy_arr, SIZE);
  clock_t end_1 = clock();

  // c = 0;
  // while (c != SIZE)
  //   printf("%d, ", arr[c++]);
  // printf("\n");
  // c = 0;
  // while (c != SIZE)
  //   printf("%d, ", copy_arr[c++]);
  // printf("\n");

  double time = ((double)(end - start)) / CLOCKS_PER_SEC;
  double time_1 = ((double)(end_1 - start_1)) / CLOCKS_PER_SEC;
  printf("Time spended arr: %g\n", time);
  printf("Comparisons 1 times: %d\n", compare);
  printf("Comparisons 2 times: %d\n", compare_1);
  printf("Time spended copy arr: %g\n", time_1);

  return 0;
}

int gnrt_nmb(int min, int max)
{
  srand(time(NULL));
  return rand() % (max - min + 1) + min;
}

int *gnrt_int_arr(int arr[], int min, int max, int len)
{
  srand(time(NULL));
  for (int i = 0; i < len; i++)
    arr[i] = rand() % (max - min + 1) + min;
  return arr;
}

int bubble_sort_1(int a[], int len)
{
  int changed;
  int n = SIZE;
  int counter = 0;
  do
  {
    changed = 0;
    for (int i = 1; i < n; i++)
    {
      if (a[i - 1] > a[i])
      {
        swap(&a[i - 1], &a[i]);
        changed = 1;
      }
      counter++;
    }
    n -= 1;
  } while (changed != 0);

  return counter;
}

// int copy_arr_2[SIZE] = {10, 9, 5, 7, 0, 5, 4, 3, 2, 1};
int selected_sort(int *a, int len)
{
  int n = SIZE;
  int ctr = 0;
  int to_cng = 0;
  int changed;
  int counter = 0;

  do
  {
    changed = 0;

    int first = a[ctr];
    for (int i = ctr + 1; i < n; i++)
    {
      if (first > a[i])
      {
        to_cng = i;
        first = a[i];
        changed = 1;
      }
      counter++;
    }
    if (changed)
      swap(&a[ctr], &a[to_cng]);
    ctr++;
  } while (ctr != len);

  return counter;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}