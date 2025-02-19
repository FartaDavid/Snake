#ifndef HEADER_H
#define HEADER_H

#define N 20
#define NN 400

typedef struct {
    int x;
    int y;
} Point;

void fillboard(char board[N][N]);
void printboard(char board[N][N]);
void keyboard(char board[N][N], int *ok, Point tail[NN], int *tail_length, char *lastchar);
void restore_terminal();
void configure_terminal();
int kbhit();
void randomfood(char board[N][N], int count);
void movebody(char board[N][N], int ok, Point tail[NN], int *tail_length, int i, int j);
void printbody(char board[N][N], Point tail[NN], int *tail_length);

#endif