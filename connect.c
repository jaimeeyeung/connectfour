#include "connect.h"
#include "cs136-trace.h"
#include <stdio.h>
#include <stdbool.h>

char board[7][6]; // setting up game board, 7 rows, 6 columns
const int ROWS = 7; // number of rows
const int COLS = 6; // number of columns
const char EMPTY = '_';

const int ACTIVE_GAME = 1;
const int GAME_OVER = 2;
const int GAME_DRAW = 3;
const int ERROR_INVALID_PLAYER_CODE = 4;
const int ERROR_INVALID_SLOT = 5;

// Sets up the board 
void setup_game(void) {
  // 0, 1, 2
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      board[r][c] = EMPTY;
    }
  }
  print_board();
}

// check to see if a player won
bool check_winner(int row, int column) {
  const int first_col = 0;
  const int first_row = 0;
  const int last_col = 5; //7
  const int last_row = 6;
  int counter = 0; // counting for
  int r = row;
  int c = column;
  
  char ch = board[r][c]; // current char you are checking
  if (ch == EMPTY) return false;

  // checks horizontally
  // checking horizontal behind
  while ((r >= first_row) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      --r;
    } else {
      break;
    }
  }

  r = row;
  c = column;
  

  // checking horizonal infront
  while ((r <= last_row) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      ++r;
    } else {
      break;
    }
  }

  if (counter > 4) {
    return true;
  }
  r = row;
  c = column;
  
  counter = 0;
  // checking vertical below
  while ((c >= first_col) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      --c;
    } else {
      break;
    }
  }

  r = row;
  c = column;
  // checking vertical above, X
  while ((c <= last_col) && (board[r][c] != EMPTY)) {
    if ((board[row][column]) == ch) {
      counter += 1;
      ++c;
    } else {
      break;
    }
  }

  if (counter > 4) {
    return true;
  }
  
  r = row;
  c = column;
 
  counter = 0;
  // checking diagonally SW
  while ((c >= first_col) && (r >= first_row) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      --c;
      --r;
    } else {
      break;
    }
  }
  
  r = row;
  c = column;
  //checking diagonally NE
  while ((c <= last_col) && (r <= last_row) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      ++c;
      ++r;
    } else {
      break;
    }
  }

  if (counter > 4) {
    return true;
  }
  r = row;
  c = column;
  
  counter = 0;
  // checking diagonally NW
  while ((c >= first_col) && (r <= last_row) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      --c;
      ++r;
    } else {
      break;
    }
  }

  r = row;
  c = column;

  // checking diagonally SE
  while ((c <= last_col) && (r >= first_col) && (board[r][c] != EMPTY)) {
    if ((board[r][c]) == ch) {
      counter += 1;
      ++c;
      --r;
    } else {
      break;
    }
  }
  
  if (counter > 4) {
    return true;
  } else {
    return false;
  }
}


// Inputs 'ch' onto the given row
// Returns `true` if this move is a win, `false` if ongoing.
int game_input(char ch, int row) {

  if ((ch != 'X') && (ch != 'O')) {
    return ERROR_INVALID_PLAYER_CODE;
  } else if (row < 0 || row > 6) {
    return ERROR_INVALID_SLOT;
  }

  int first_empty = -1;
  int used_piece = 0;
  for (int c = 0; c < COLS; ++c) {
    // find the first 'empty' slot aka == EMPTY
    if (board[row][c] == EMPTY) {
      first_empty = c;
      used_piece += 1;
      break;
    } else {
      first_empty = -1;
    }
  }

  if (first_empty == -1) { // row was full, not empty
    return ERROR_INVALID_SLOT;
  } else { // row was not full
    board[row][first_empty] = ch; 
  }

  // print the board after placing in the input
  print_board();

  // check if you have a win (or a draw)
  //column = first_empty
  if (check_winner(row, first_empty)) {
    return GAME_OVER;
  } else if (used_piece >= 42) { // check if it is a draw(each player uses 21 pieces, 42 pieces in total)
    return GAME_DRAW;
  }

  // if nothing else, means game is still active
  return ACTIVE_GAME;
}


// Prints the current board
// see connect.h for documentation
void print_board (void) {
  for (int c = COLS - 1; c >= 0; --c) {
    printf("|");
    for (int r = 0; r < ROWS; ++r) {
      printf("%c|", board[r][c]);
    }
    printf("\n");
  }
  printf(" ");
  for (int r = 0; r < ROWS; ++r) {
    if (r == (ROWS - 1)) {
      printf("%d", r);
    } else {
      printf("%d ", r);
    }
  }
  printf("\n");
  printf("\n");
}
