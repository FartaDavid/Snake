#include <stdio.h>
#include "game_mechanincs.h"

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

// Function to print the body of the snake
void printbody(char board[N][N], Point tail[NN], int *tail_length) {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (board[i][j] == '#') {
                board[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < *tail_length; i++) {
        board[tail[i].x][tail[i].y] = '#';
    }
}