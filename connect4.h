/*********************************************************
 * File: connect4.h
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Prototypes for connect4.c
 * 
 * Date Created: April 14, 2026
 * 
*********************************************************/


#ifndef CONNECT4_H
#define CONNECT4_H

#define BG_BLUE   "\033[44m"
#define RED_DISC  "\033[41m"
#define YEL_DISC  "\033[43m"
#define RESET     "\033[0m"


int play_game(int rows, int cols, int board[rows][cols], int height[cols]);
int make_play(int rows, int cols, int board[rows][cols], int height[cols]);
int check_win(int rows, int cols, int board[rows][cols]);
void render(int rows, int cols, int board[rows][cols], int sel_col);



#endif