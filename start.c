#include <stdio.h>
#include "header.h"

void fillboard(char board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == N - 1) {
                board[i][j] = '-';
            } else if (j == 0 || j == N - 1) {
                board[i][j] = '|';
            } else if (board[i][j] != '+') {
                board[i][j] = ' ';
            }
        }
    }
}

void printboard(char board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}