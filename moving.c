#include <stdio.h>
#include "header.h"

// Function to move the snake
void move(char board[N][N], int x, int y, int *ok) {
    int i, j;
    for (i = 1; i < N - 1; i++) {
        for (j = 1; j < N - 1; j++) {
            if (board[i][j] == '+') {
                if (board[i + x][j + y] == '|' || board[i + x][j + y] == '-') {
                    *ok = 0;
                    return;
                } else if (board[i + x][j + y] == '*') {
                    board[i + x][j + y] = '+';
                    board[i][j] = ' ';
                    randomfood(board, 1);
                    return;
                } else {
                board[i + x][j + y] = '+';
                board[i][j] = ' ';
                return;
                }
            }
        }
    }
}

// Function to get the input from the keyboard and move the snake
void keyboard(char board[N][N], int* ok) {
    char c = getchar();
    if (c == 'w') {
        move(board, -1, 0, ok);
    } else if (c == 'd') {
        move(board, 0, 1, ok);
    } else if (c == 's') {
        move(board, 1, 0, ok);
    } else if (c == 'a') {
        move(board, 0, -1, ok);
    } else {
        keyboard(board, ok);
    }
}

