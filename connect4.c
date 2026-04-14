/*********************************************************
 * File: connect4.c
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Connect 4 game main logic
 *        
 * Date Created: April 13, 2026
 * 
*********************************************************/

#include "settings.h"

#define RED 1
#define YELLOW 2

int main(int argc, char* argv[]) {

	struct GameRules ruleset = CONNECT4;

	int board[ruleset.rows][ruleset.cols];	// Row-major array of gameboard
	int height[ruleset.cols];	// Tracks current height of chips in each col

	memset(board, 0, sizeof(board));
	memset(height, 0, sizeof(height));

	play_game(ruleset.rows, ruleset.cols, board, height);

	return 0;
}

int play_game (int rows, int cols, int board[rows][cols], int height[cols]) {
	int turn = RED;
	int winner = 0;

	// print board

	while (winner == 0) {

		int play = make_play(rows, cols, height);
		board[height[play]][play];

		// print board

		// Switch turn
		if (turn == RED) {
			turn = YELLOW;
		}
		else if (turn == YELLOW) {
			turn = RED;
		}

		// Check for win
		/*if (winner = check_win > 0) {
	
		}*/

	}

	// Print win screen

}

int make_play(int rows, int cols, int height[cols]) {
	
    struct termios old_tio;
    enableRawMode(&old_tio);

	int sel_col = (cols - 1) / 2;
	char c;

	// Use stdin arrow keys to choose a number from 0 to max row
	while(c != '\n' || height[sel_col] == rows) {

		read(STDIN_FILENO, &c, 1);
		if (c == '\x1b') { // escape sequence
            char seq[2];
            read(STDIN_FILENO, &seq[0], 1);
            read(STDIN_FILENO, &seq[1], 1);

            if (seq[0] == '[') {
                if (seq[1] == 'C') { // right arrow
                    if (sel_col < cols - 1)
                        sel_col++;
                } 
                else if (seq[1] == 'D') { // left arrow
                    if (sel_col > 0)
                        sel_col--;
                }
            }
        }

		// print selection arrow
		
	}
	

	disableRawMode(&old_tio);

	height[sel_col]++;
	return sel_col;



}

void render(int rows, int cols, int board[rows][cols]) {

    printf("\033[H"); // or "\033[2J\033[H" if you want full clear

    for (int r = rows - 1; r >= 0; r--) {
        for (int c = 0; c < cols; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    fflush(stdout);
}







