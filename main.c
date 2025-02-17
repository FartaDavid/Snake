#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char board[N][N];

int main() {
    int end = 1;
    board[10][10] = '+'; // initial position
    fillboard(board);
    while (end) {
        system("clear");
        printboard(board);
        keyboard(board);
        system("clear");
    }
    return 0;
}