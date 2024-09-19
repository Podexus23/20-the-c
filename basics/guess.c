/*
  Practice Project: Number Guessing Game
  Write a program where the computer generates a random number and the player tries to guess it.
  Use functions to break down tasks (e.g., generateNumber(), getUserInput(), checkGuess()).
*/

/*
  Add:
    check for out of range guesses and give one more chance.
    replay game if guess was right
    check for guess strike
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gnrt_nmb(int, int);
int get_user_input(void);
void check_guess(int, int);

int main(int argc, char **argv)
{
  int num, user_num = 0;
  int min = 0;
  int max = 5;
  if (argc > 2)
  {
    min = (atoi(argv[1]) > 0) ? atoi(argv[1]) : 0;
    max = (atoi(argv[2]) > 0) ? atoi(argv[2]) : 5;
  }
  num = gnrt_nmb(min, max);
  user_num = get_user_input();
  check_guess(num, user_num);

  return 0;
}

int gnrt_nmb(int min, int max)
{
  srand(time(NULL));
  return rand() % (max - min + 1) + min;
}

int get_user_input(void)
{
  int one;
  printf("try to guess the number: ");
  scanf("%d", &one);
  return one;
}

void check_guess(int num_rn, int num_user)
{
  if (num_rn == num_user)
    printf("Congrats, the number was: %d\n", num_user);
  else
    printf("Sorry, the number was: %d\n", num_rn);
}