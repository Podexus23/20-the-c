#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_TASK 100

struct task
{
  int id;
  char task[50];
};
struct task tasks[MAX_SIZE];
static int tasks_i = 0;

/*
save tasks
delete tasks
modify tasks
print tasks

save task to file
read file with tasks

save/read/modify directly from file
*/
int add_task();
int add_task_f(char *filename);
int get_task_f(char *filename);

int main(int argc, char **argv)
{
  char *file = "task.txt";

  // add_task();
  add_task_f(file);
  get_task_f(file);
  return 0;
}

int add_task()
{
  char line[MAX_TASK];

  if (tasks_i > MAX_SIZE)
  {
    printf("Sorry to much tasks");
    return 1;
  }

  fgets(line, MAX_TASK, stdin);
  strcpy(tasks[tasks_i].task, line);
  tasks[tasks_i].id = tasks_i + 1;
  tasks_i++;

  return 0;
}

int add_task_f(char *filename)
{
  char line[MAX_TASK];
  FILE *fp = fopen(filename, "w");

  if (tasks_i > MAX_SIZE)
  {
    printf("Sorry to much tasks");
    return 1;
  }

  fgets(line, MAX_TASK, stdin);
  strcpy(tasks[tasks_i].task, line);
  fwrite(&tasks[tasks_i], sizeof(struct task), 1, fp);
  tasks[tasks_i].id = tasks_i++;

  fclose(fp);
  return 0;
}

int get_task_f(char *filename)
{
  struct task *task = malloc(sizeof(struct task));
  FILE *fp = fopen(filename, "r");

  if (tasks_i > MAX_SIZE)
  {
    printf("Sorry to much tasks");
    return 1;
  }

  size_t res = fread(task, sizeof(struct task), 1, fp);
  printf("How much the fish: %ld\n", res);
  printf("ID: %d, task: %s", task->id, task->task);
  free(task);
  fclose(fp);
  return 0;
}