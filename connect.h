// constants to distinguish game status
extern const int ACTIVE_GAME; //= 1;
extern const int GAME_OVER; //= 2;
extern const int GAME_DRAW; //= 3;
extern const int ERROR_INVALID_PLAYER_CODE; //= 4;
extern const int ERROR_INVALID_SLOT; //= 5;

// Sets up the board 
void setup_game(void);

// Inputs 'ch' onto the given row
// Returns a value between 0..N that represents the return 'code'
int game_input(char ch, int row);

// Prints the current board
void print_board(void);
