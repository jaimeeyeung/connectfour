#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "connect.h"

int main(void) {
  char c;
  int d;
  int status = ACTIVE_GAME;
  setup_game();

  while (status == ACTIVE_GAME) {
    if (scanf(" %c", &c) != 1) { 
      printf("ERROR: cannot read player code\n");
      break;
    }
    } 
    else if (scanf("%d", &d) == 1){
      scanf("%d", &d);
      trace_char(c);
      trace_int(d);
      status = game_input(c, d);
    } else {
      printf("ERROR: cannot read slot number\n");
      break;
    }
  }

  if (status == GAME_OVER) {
    printf("Victory! Player %c has won!\n", c);
  } else if (status == GAME_DRAW) {
    printf("Draw! No player has won!\n");
  } else if (status == ERROR_INVALID_PLAYER_CODE) {
    printf("ERROR: invalid player code: %c\n", c);
  } else if (status == ERROR_INVALID_SLOT) {
    printf("ERROR: invalid slot number: %d\n", d);
  } 
  return EXIT_SUCCESS;
}
