#ifndef HEADER_H
#define HEADER_H

#define N 20

void fillboard(char board[N][N]);
void printboard(char board[N][N]);
void keyboard(char board[N][N], int *ok);
void restore_terminal();
void configure_terminal();
int kbhit();
void randomfood(char board[N][N], int count);

#endif