#include <stdio.h>
#include <stdlib.h>

//The empty character in the board
const char EMPTY = ' ';
//The character for the first player in the board
const char X = 'X';
//The character for the second player in the board
const char O = 'O';

/**
 * Checks the given board for winners and returns the char of the winner
 */
char winnerOf(char board[]) {
    for (int i = 0; i < 3; i++) {
        //Checks rows
        if (board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2]) {
            return board[3 * i];
        }
        //Checks columns
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 3 * 2]) {
            return board[i];
        }
    }
    //Checks diagonals
    if (board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6]) {
        return board[4];
    }
    return EMPTY;
}

/**
 * Prints the given board
 */
void printBoard(char board[9]) {
    for (int i = 0; i < 9; i++) {
        printf("%c", board[i]);
        printf("%c", ' ');
        if ((i + 1) % 3 == 0) {
            printf("%c", '\n');
        }
    }
}

/**
 * Clears the console
 */
void clearScreen() {
    for (int j = 0; j < 100; j++) {
        printf("%c", '\n');
    }
}

/**
 * Entry point of the program
 */
int main() {
    char board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = EMPTY;
    }
    char winner = EMPTY;
    for (int i = 0; winner == EMPTY; i++) {
        clearScreen();
        printBoard(board);
        char playerChar = i % 2 == 0? X : O;
        int locationToMove;
        do {
            int row;
            int column;
            printf("Player %c, which column will you move in? ", playerChar);
            scanf("%d", &column);
            printf("Player %c, which row will you move in? Enter -1 if you wish to re-select column. ", playerChar);
            scanf("%d", &row);
            locationToMove = (row - 1) * 3 + (column - 1);
            if (row < 1 || row > 3 || column < 1 || column > 3) {
                locationToMove = -1;
            }
        } while(locationToMove < 0 || locationToMove >= 9 || board[locationToMove] != EMPTY);
        board[locationToMove] = playerChar;
        winner = winnerOf(board);
    }
    clearScreen();
    printBoard(board);
    printf("Player %c is the winner!", winner);
    return 0;
}