#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h>

char board[N][N];

int main() {
    int end = 1;
    configure_terminal();
    board[10][10] = '+'; // initial position
    fillboard(board);
    randomfood(board, 5);
    printf("\033[H\033[J");
    while (end) {
        printboard(board);
        keyboard(board, &end);
        printf("\033[H\033[J");
    }
    printf("Game over!\n");
    sleep(3);
    restore_terminal();
    return 0;
}