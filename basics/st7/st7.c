/**
 *
 * ### **Stage 7: Advanced Pointers (Pointer to Pointer)**
#### Topics:
- **Pointer to Pointer:**
  - Double pointers (pointer to pointer)
  - Pointers with multi-dimensional arrays
  - Pointer to functions

#### **Practice Project: Tic-Tac-Toe Game**
Write a tic-tac-toe game that uses a pointer to pointer (2D array) to manage the game board.
Allow two players to play and determine the winner.

 */

/*
  - Double pointers (pointer to pointer)
  - Pointers with multi-dimensional arrays
  - Pointer to functions
*/

/*
tic tac toe

make field+
renew field+
show moves+
make moves+
make players+
congrats player on win+

check for win cindition+

or show draw
*/

#include <stdio.h>

#define F_SIZE 3

enum
{
  X = 'X',
  O = 'O',
  EMPTY = '-'
};

void print_field(void);
void clean_field(void);
void make_field(void);

void game_cycle(void);
int make_a_move(char);

int check_win_condition(void);
int vert_check(void);
int horz_check(void);
int diag_down_check(void);
int diag_up_check(void);
int draw_check(void);

char field[F_SIZE][F_SIZE];
int field_pl = F_SIZE * F_SIZE;
int moves = 0;

int main(void)
{
  make_field();
  print_field();
  game_cycle();
}

void print_field(void)
{
  printf("----------------------------\n");
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {

      printf("|%c|", field[i][j]);
    }
    printf("\n");
  }
}

void clean_field(void)
{
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {
      field[i][j] = EMPTY;
    }
  }
}

void make_field(void)
{
  int c = 1;
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {
      field[i][j] = EMPTY;
      // field[i][j] = '0' + c;
      c++;
    }
  }
}

int make_a_move(char player_c)
{
  int x;
  int y;
  printf("Please enter coordsto make a move(str row):\n");
  scanf("%d %d", &x, &y);
  if ((x > F_SIZE || x < 0) || (y > F_SIZE || y < 0))
  {
    printf("move: sorry wrong coords, try somting more than 0, and less that %d\n", F_SIZE + 1);
    return make_a_move(player_c);
  }
  if (field[x - 1][y - 1] != EMPTY)
  {
    printf("move: sorry this place is not empty, try smth different\n");
    return make_a_move(player_c);
  }
  field[x - 1][y - 1] = player_c;
  moves++;
  printf("Moves: %d\n", moves);
  return 0;
}

void game_cycle(void)
{
  int player_1 = X;
  int player_2 = O;
  int main_pl = player_1;
  int cond = 1;
  do
  {
    make_a_move(main_pl);
    cond = check_win_condition();
    if (cond != 0)
      main_pl = (main_pl == player_1) ? player_2 : player_1;
    print_field();
  } while (cond != 0 && cond != 2);
  if (cond == 2)
    printf("It's a draw sorry\n");
  else
    printf("Congrats player: %c\n", main_pl);
}

int check_win_condition(void)
{
  printf("checked\n");

  if (vert_check() == 0)
    return 0;
  if (horz_check() == 0)
    return 0;
  if (diag_down_check() == 0)
    return 0;
  if (diag_up_check() == 0)
    return 0;
  if (draw_check() == 0)
    return 2;

  return 1;
}

int vert_check(void)
{
  int beacon;
  int changed;

  for (int i = 0; i < F_SIZE; i++)
  {
    changed = 0;
    for (int j = 0; j < F_SIZE; j++)
    {
      if (j == 0)
        beacon = field[j][i];
      else if (field[j][i] == beacon && field[j][i] != EMPTY)
        continue;
      else
        changed++;
    }
    if (changed == 0)
      break;
  }

  if (changed == 0)
    return 0;
  else
    return 1;
}

int horz_check(void)
{
  int beacon;
  int changed;

  for (int i = 0; i < F_SIZE; i++)
  {
    changed = 0;
    for (int j = 0; j < F_SIZE; j++)
    {
      if (j == 0)
        beacon = field[i][j];
      if (field[i][j] == beacon && field[i][j] != EMPTY)
        continue;
      else
        changed++;
    }
    if (changed == 0)
      break;
  }

  if (changed == 0)
    return 0;
  else
    return 1;
}

int diag_down_check(void)
{
  int beacon = field[0][0];
  int changed = 0;
  for (int i = 1; i < F_SIZE; i++)
  {
    if (field[i][i] == beacon && field[i][i] != EMPTY)
      continue;
    else
      changed++;
  }

  if (changed == 0)
    return 0;
  else
    return 1;
}

int diag_up_check(void)
{
  int beacon = field[F_SIZE - 1][0];
  int changed = 0;
  for (int i = 1; i < F_SIZE; i++)
  {
    if (field[F_SIZE - i - 1][i] == beacon && field[F_SIZE - i - 1][i] != EMPTY)
      continue;
    else
      changed++;
  }

  if (changed == 0)
    return 0;
  else
    return 1;
}

int draw_check(void)
{
  if (moves == field_pl)
    return 0;
  return 1;
}