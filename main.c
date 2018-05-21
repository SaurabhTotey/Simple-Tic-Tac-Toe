#include <stdio.h>
#include <stdlib.h>
#include <SDL_video.h>
#include <SDL_system.h>
#include <stdbool.h>
#include <SDL_events.h>
#include <SDL_ttf.h>

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
        if (board[3 * i] != EMPTY && board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2]) {
            return board[3 * i];
        }
        //Checks columns
        if (board[i] != EMPTY && board[i] == board[i + 3] && board[i + 3] == board[i + 3 * 2]) {
            return board[i];
        }
    }
    //Checks diagonals
    if (board[4] != EMPTY && board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6]) {
        return board[4];
    }
    return EMPTY;
}

/**
 * Prints the given board
 */
void drawBoard(const char board[9], SDL_Renderer* renderer, SDL_Texture* xTexture, SDL_Texture* oTexture) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < 2; i++) {
        SDL_Rect vertical = { 300 + 300 * i - 25, 50, 50, 800 };
        SDL_RenderFillRect(renderer, &vertical);
        SDL_Rect horizontal = { 50, 300 + 300 * i - 25, 800, 50 };
        SDL_RenderFillRect(renderer, &horizontal);
    }
    for (int i = 0; i < 9; i++) {
        if (board[i] != EMPTY) {
            SDL_Rect r = {100 * i % 3, 100 * i / 3, 300, 300};
            SDL_RenderCopy(renderer, board[i] == X? xTexture : oTexture, NULL, &r);
        }
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
    SDL_Window* window = SDL_CreateWindow("Tic Tac Toe!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    TTF_Font* font = TTF_OpenFont("OpenSans-Regular.ttf", 50);
    SDL_Color black = {0, 0, 0, 1};
    SDL_Texture* xTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderGlyph_Blended(font, X, black));
    SDL_Texture* oTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderGlyph_Blended(font, O, black));

    SDL_RenderSetLogicalSize(renderer, 900, 900);
    int turnCount = 0;
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            Uint32 type = event.type;
            if (type == SDL_QUIT) {
                SDL_DestroyTexture(xTexture);
                SDL_DestroyTexture(oTexture);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            } else if (type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x / 300;
                int y = event.button.y / 300;
                board[y * 3 + x] = turnCount % 2 == 0? X : O;
                turnCount++;
            }
        }
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderClear(renderer);
        drawBoard(board, renderer, xTexture, oTexture);
        SDL_RenderPresent(renderer);
    }
}