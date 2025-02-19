#include <stdio.h>
#include "game_mechanincs.h"

// Function to move the snake
void move(char board[N][N], int x, int y, int *ok, Point tail[NN], int *tail_length) {
    int i, j;
    for (i = 1; i < N - 1; i++) {
        for (j = 1; j < N - 1; j++) {
            if (board[i][j] == '+') {
                if (board[i + x][j + y] == '|' || board[i + x][j + y] == '-' || board[i + x][j + y] == '#') {
                // Verifying if the snake is not hitting the wall or itself
                    *ok = 0;
                    return;
                } else if (board[i + x][j + y] == '*') {
                // Verifying if the snake is eating the food
                    board[i + x][j + y] = '+';
                    board[i][j] = ' ';
                    randomfood(board, 1);
                    movebody(board, 1, tail, tail_length, i, j);
                    return;
                } else {
                // Moving the snake in blank spaces
                board[i + x][j + y] = '+';
                board[i][j] = ' ';
                movebody(board, 0, tail, tail_length, i, j);
                return;
                }
            }
        }
    }
}

// Function to get the input from the keyboard and move the snake
void keyboard(char board[N][N], int* ok, Point tail[NN], int *tail_length, char *lastchar) {
    char c;
    if (!kbhit()) {
        c = *lastchar;
    }
    else {
        c = getchar();
    }
    if (c == 'w' && *lastchar != 's') {
        *lastchar = 'w';
        move(board, -1, 0, ok, tail, tail_length);
    } else if (c == 'd' && *lastchar != 'a') {
        *lastchar = 'd';
        move(board, 0, 1, ok, tail, tail_length);
    } else if (c == 's' && *lastchar != 'w') {
        *lastchar = 's';
        move(board, 1, 0, ok, tail, tail_length);
    } else if (c == 'a' && *lastchar != 'd') {
        *lastchar = 'a';
        move(board, 0, -1, ok, tail, tail_length);
    }
}

// Function to remember the body of the snake
void movebody(char board[N][N], int ok, Point tail[NN], int *tail_length, int i, int j) {
    if (ok == 1) {
    // If the snake is eating the food, then increase its body
        tail[*tail_length].x = i;
        tail[*tail_length].y = j;
        (*tail_length)++;
    } else {
    // If snake is not eating then I move the body where its head was
        for (int k = 0; k < *tail_length - 1; k++) {
            tail[k].x = tail[k + 1].x;
            tail[k].y = tail[k + 1].y;
        }
        tail[*tail_length - 1].x = i;
        tail[*tail_length - 1].y = j;
        
    }
}