#include <stdio.h>
#include "header.h"

// Function to fill the board with the border and empty spaces
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

// Function to print the board
void printboard(char board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}