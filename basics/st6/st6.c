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

int main(void)
{

  FILE *fp = fopen("task.txt", "w");
  fclose(fp);
  return 0;
}