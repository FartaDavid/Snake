#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"
#include <time.h>
#include <stdlib.h>

// Function to configure the terminal for non-canonical mode
void configure_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to restore the terminal to its original state
void restore_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Re-enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to check if a key has been pressed
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Function to generate random food on the board
void randomfood(char board[N][N], int count) {
    // Taking current time as seed
    unsigned int seed = time(0);
    for (int i = 0; i < count; i++) {
        // Generate a random number in the range [min, max]
        int rd_num1 = rand_r(&seed) % (18 - 1 + 1) + 1;
        int rd_num2 = rand_r(&seed) % (18 - 1 + 1) + 1;
        if (board[rd_num1][rd_num2] == ' ') {
            board[rd_num1][rd_num2] = '*';
        } else {
            i--;
        }
    }
}