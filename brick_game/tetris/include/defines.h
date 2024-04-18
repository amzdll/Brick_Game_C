#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_

// Tetris board
#define HEIGHT 20
#define WIDTH 10

// Tetris Block
#define BLOCKS_COUNT 7

#define I_BLOCK    \
  (int[1][4]) {    \
    { 1, 1, 1, 1 } \
  }

#define J_BLOCK            \
  (int[2][3]) {            \
    {2, 0, 0}, { 2, 2, 2 } \
  }

#define L_BLOCK            \
  (int[2][3]) {            \
    {0, 0, 3}, { 3, 3, 3 } \
  }

#define O_BLOCK      \
  (int[2][2]) {      \
    {4, 4}, { 4, 4 } \
  }

#define S_BLOCK            \
  (int[2][3]) {            \
    {0, 5, 5}, { 5, 5, 0 } \
  }

#define Z_BLOCK            \
  (int[2][3]) {            \
    {6, 6, 0}, { 0, 6, 6 } \
  }

#define T_BLOCK            \
  (int[2][3]) {            \
    {0, 7, 0}, { 7, 7, 7 } \
  }

typedef enum {
  START = 0,
  SPAWN = 1,
  MOVING = 2,
  SHIFTING = 3,
  COLLIDE = 4,
  GAME_OVER = 5,
  EXIT_STATE = 6
} game_state;

// ncurses key
// #define ESCAPE 27

#define WIN_INIT(time)    \
  {                       \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
  }

#define GET_USER_INPUT getch()

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)
#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c)
#define CLEAR_BACKPOS(y, x) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), ' ')

#define YOU_WON "tests/game_progress/you_won.txt"
#define YOU_LOSE "tests/game_progress/you_lose.txt"
#define LEVEL_DIR "tests/levels/level_"
#define INTRO_MESSAGE "Press ENTER to start!"
#define INTRO_MESSAGE_LEN 21
#define LEVEL_CNT 5
#define LEVELNAME_MAX 25

#define MAX_WIN_COUNT 10

#define ROWS_MAP 20
#define COLS_MAP 90

#define BOARDS_BEGIN 2

#define INITIAL_TIMEOUT 150

//#define BOARD_N (ROWS_MAP + MAP_PADDING)
#define BOARD_N ROWS_MAP
#define BOARD_M 30
#define HUD_WIDTH 12
#define MAP_PADDING 3

#define BANNER_N 10
#define BANNER_M 100

#define NO_INPUT -1

#define ESCAPE 27
#define ENTER_KEY 10

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_
