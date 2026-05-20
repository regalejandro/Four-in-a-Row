/*********************************************************
 * File: cpu.c
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Connect 4 algorithm using minimax with 
 * 				alpha-beta pruning
 *        
 * Date Created: May 18, 2026
 * 
*********************************************************/

#include "cpu.h"
#include "settings.h"

void generate_val_map(int rows, int cols, int map[rows][cols]) {

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {

			int possibilities = 0;

			//horizontal check
			for (int i = 0; i < ruleset.win_num; i++) {
				if (c - i >= 0 && c + i < cols)
					possibilities++;
			}

			// vertical check
			for (int i = 0; i < ruleset.win_num; i++) {
				if (r - i >= 0 && r + i < rows)
					possibilities++;
			}

			// diagonal (/) check 
			int right = ruleset.win_num;
			int left = ruleset.win_num;
			int diag_len = 0;

			for (int i = ruleset.win_num - 1; right == ruleset.win_num || left == ruleset.win_num; i--) {
				if (r + i < ruleset.rows && c + i < ruleset.cols && right == ruleset.win_num)
					right = i;
				if (r - i >= 0 && c - i >= 0 && left == ruleset.win_num)
					left = i;
			}
			diag_len = right + left + 1;
			if (diag_len >= ruleset.win_num)
				possibilities += diag_len - ruleset.win_num + 1;

			// diagonal (\) check 
			right = ruleset.win_num;
			left = ruleset.win_num;
			diag_len = 0;

			for (int i = ruleset.win_num - 1; right == ruleset.win_num || left == ruleset.win_num; i--) {
				if (r - i >= 0 && c + i < ruleset.cols && right == ruleset.win_num)
					right = i;
				if (r + i < ruleset.rows && c - i >= 0 && left == ruleset.win_num)
					left = i;
			}
			diag_len = right + left + 1;
			if (diag_len >= ruleset.win_num)
				possibilities += diag_len - ruleset.win_num + 1;

			map[r][c] = possibilities;
		}
	}

}

int get_score(int turn, int rows, int cols, int board[rows][cols], int map[rows][cols]) {

	int score = 0;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (board[r][c] == turn)
				score += map[r][c];
		}
	}

	return score;
}

void print_val_map(int rows, int cols, int map[rows][cols]) {
	for (int r = rows - 1; r >= 0; r--) {
		for (int c = 0; c < cols; c++) {
			printf("\t%d", map[r][c]);
		}
		printf("\n");
	}
	printf("\n\n");
}







