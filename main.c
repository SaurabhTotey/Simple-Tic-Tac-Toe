#include <stdio.h>

const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';

/**
 * Checks the given board for winners
 */
char winner(char board[]) {

}

/**
 * Prints the given board
 */
void printBoard(char board[]) {
    for(int i = 0; i < 9; i++) {
        printf("%c", board[i]);
        printf("%c", ' ');
        if ((i + 1) % 3 == 0) {
            printf("%c", '\n');
        }
    }
}

int main() {
    char board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = EMPTY;
    }
    printBoard(board);
    return 0;
}