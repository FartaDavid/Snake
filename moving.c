#include <stdio.h>
#include "header.h"

void move(char board[N][N], int x, int y) {
    int i, j;
    for (i = 1; i < N - 1; i++) {
        for (j = 1; j < N - 1; j++) {
            if (board[i][j] == '+') {
                board[i + x][j + y] = '+';
                board[i][j] = ' ';
                return;
            }
        }
    }
}

void keyboard(char board[N][N]) {
    char c = getchar();
    if (c == 'w') {
        move(board, -1, 0);
    } else if (c == 'd') {
        move(board, 0, 1);
    } else if (c == 's') {
        move(board, 1, 0);
    } else if (c == 'a') {
        move(board, 0, -1);
    } else {
        keyboard(board);
    }
}

