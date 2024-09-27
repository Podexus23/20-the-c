/*

### **Stage 6: File Handling**
#### Topics:
- **File Input/Output:**
  - Opening and closing files (`fopen()`, `fclose()`)
  - Reading from and writing to files (`fread()`, `fwrite()`, `fprintf()`, `fscanf()`)
  - File modes (read, write, append)

#### **Practice Project: To-Do List Application**
Create a to-do list application where the user can add, delete, or modify tasks. Save the tasks to a file and load them when the program starts.

*/

/*
ну вот это будет весело, тут я пока нихуя не знаю, надо делать отдельную папку для этого дела, нааверное
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task
{
  int id;
  char task[50];
};

int save(char *filename, struct task *p, int n);
int load(char *filename);

int main(void)
{
  char *filename = "task.txt";
  struct task st6 = {1, "finish the 6-th task"};
  struct task tasks[] =
      {
          {1, "finish the 6-th task\n"},
          {2, "do something\n"},
          {3, "finish the 7th task\n"}};
  int n = sizeof(tasks) / sizeof(tasks[0]);

  save(filename, tasks, n);
  load(filename);

  return 0;
}

int save(char *filename, struct task *p, int n)
{
  char *c;
  int size = n * sizeof(struct task);

  FILE *fp = fopen(filename, "wb");

  if (!fp)
  {
    printf("Error occured while oppening\n");
    return 1;
  }

  c = (char *)&n;
  for (int i = 0; i < sizeof(n); i++)
  {
    putc(*c++, fp);
  }
  c = (char *)p;
  for (int i = 0; i < size; i++)
  {
    putc(*c, fp);
    c++;
  }
  fclose(fp);
  return 0;
}

int load(char *filename)
{
  char *c;
  int m = sizeof(int);
  int n;
  FILE *fp = fopen(filename, "rb");

  if (!fp)
  {
    printf("Error occured while opening file\n");
    return 1;
  }

  int *ptr_count = malloc(m);
  c = (char *)ptr_count;

  while (m > 0 && (*c = getc(fp)) != EOF)
  {
    c++;
    m--;
  }

  n = *ptr_count;
  free(ptr_count);

  struct task *ptr = malloc(n * sizeof(struct task));
  c = (char *)ptr;

  while ((*c = getc(fp)) != EOF)
  {
    c++;
  }

  printf("Tasks:\n");

  for (int i = 0; i < n; i++)
  {
    printf("%d. %s \n", (ptr + i)->id, (ptr + i)->task);
  }
  fclose(fp);
  free(ptr);
  return 0;
}
