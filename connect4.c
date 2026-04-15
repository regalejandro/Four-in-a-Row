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

#include "connect4.h"
#include "settings.h"

#define RED 1
#define YELLOW 2

int main(int argc, char* argv[]) {

	ruleset = CONNECT4;

	int board[ruleset.rows][ruleset.cols];	// Row-major array of gameboard
	int height[ruleset.cols];	// Tracks current height of chips in each col

	memset(board, 0, sizeof(board));
	memset(height, 0, sizeof(height));

	play_game(ruleset.rows, ruleset.cols, board, height);

	return 0;
}

int play_game(int rows, int cols, int board[rows][cols], int height[cols]) {
	int turn = RED;
	int winner = 0;

	// print board
	render(rows, cols, board);

	while (1) {

		int play = make_play(rows, cols, height);
		board[height[play]][play] = turn;
		height[play]++;
		

		// print board
		render(rows, cols, board);
		
		// Check for win
		if ((winner = check_win(rows, cols, board)))
			break;

		// Switch turn
		if (turn == RED) {
			turn = YELLOW;
		}
		else if (turn == YELLOW) {
			turn = RED;
		}

	}

	if (winner == 2) {
		printf("\nDRAW!\n");
	}
	else if (winner == 1) {
		// Print win screen
		if (turn == RED)
			printf("\nRED Wins!\n");
		else if(turn == YELLOW)
			printf("\nYELLOW Wins!\n");
	}

	return 0;
}

int make_play(int rows, int cols, int height[cols]) {
	
    struct termios old_tio;
    enableRawMode(&old_tio);

	int sel_col = (cols - 1) / 2;
	char c = 0;

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

	printf("\033[?25h");

	disableRawMode(&old_tio);

	return sel_col;



}

int check_win(int rows, int cols, int board[rows][cols]) {

	int empty = 0;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {

			if (board[r][c] == 0)
				empty++;

			// Horizontal (left to right)
			if (c <= cols - ruleset.win_num) {
				if (board[r][c] != 0 &&
					board[r][c] == board[r][c + 1] &&
					board[r][c + 1] == board[r][c + 2] &&
					board[r][c + 2] == board[r][c + 3])
					return 1;
			}

			// Vertical (top to bottom)
			if (r <= rows - ruleset.win_num) {
				if (board[r][c] != 0 &&
					board[r][c] == board[r + 1][c] &&
					board[r + 1][c] == board[r + 2][c] &&
					board[r + 2][c] == board[r + 3][c])
					return 1;
			}

			// Diagonal (down and right)
			if (r <= rows - ruleset.win_num && c <= cols - ruleset.win_num) {
				if (board[r][c] != 0 &&
					board[r][c] == board[r + 1][c + 1] &&
					board[r + 1][c + 1] == board[r + 2][c + 2] &&
					board[r + 2][c + 2] == board[r + 3][c + 3])
					return 1;
			}

			// Diagonal (down and left)
			if (r <= ruleset.win_num && c >= ruleset.win_num - 1) {
				if (board[r][c] != 0 &&
					board[r][c] == board[r + 1][c - 1] &&
					board[r + 1][c - 1] == board[r + 2][c - 2] &&
					board[r + 2][c - 2] == board[r + 3][c - 3])
					return 1;
			}

			if (empty == 0 && r == rows - 1 && c == cols - 1) {
				return 2;
			}

		}

	}

	return 0;

}

#define BG_BLUE   "\033[44m"
#define RED_DISC  "\033[41m"
#define YEL_DISC  "\033[43m"
#define RESET     "\033[0m"

void render(int rows, int cols, int board[rows][cols]) {

    printf("\033[2J\033[H");
    printf("\033[?25l");

 	// horizontal blue separator between rows
    for (int c = 0; c < cols * 6; c++) {
        printf(BG_BLUE " " RESET);
    }
    printf("\n");

    for (int r = rows - 1; r >= 0; r--) {
        for (int sub = 0; sub < 2; sub++) {
            for (int c = 0; c < cols; c++) {

                int val = board[r][c];

                // LEFT GRID WALL (blue)
                printf(BG_BLUE " " RESET);

                // SLOT CONTENT (NOT blue background)
                if (val == 1) {
                    printf(RED_DISC "    " RESET);
                }
                else if (val == 2) {
                    printf(YEL_DISC "    " RESET);
                }
                else {
                    printf("    "); // empty hole
                }

                // RIGHT GRID WALL (blue)
                printf(BG_BLUE " " RESET);
            }

            printf("\n");
        }

        // horizontal blue separator between rows
        for (int c = 0; c < cols * 6; c++) {
            printf(BG_BLUE " " RESET);
        }
        printf("\n");
    }

    fflush(stdout);
}







