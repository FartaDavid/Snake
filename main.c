#include <stdio.h>
#include <stdlib.h>
#include "game_mechanincs.h"
#include <unistd.h>
#include <time.h>

char board[N][N], lastchar;
Point tail[NN];

int main() {
    int end = 1, tail_length = 0;
    configure_terminal();
    board[N/2][N/2] = '+'; // Initial position of the snake
    fillboard(board); // Filling the board with border and empty spaces
    randomfood(board, 5); // Generating 5 random foods for the snake
    printf("\033[H\033[J"); // Clearing the screen

    while (end) {
        printboard(board);
        printf("Score: %d\n", tail_length); // Printing the score
        keyboard(board, &end, tail, &tail_length, &lastchar);
        usleep(200000);
        printbody(board, tail, &tail_length); 

        if (tail_length == NN) { // Winning situation
            printf("You win!\n");
            sleep(2);
            restore_terminal();
            return 0;
        }

        printf("\033[H\033[J");
    }

    printf("Game over!\n"); // Losing situation
    sleep(2);
    restore_terminal();

    return 0;
}