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

#define BG_RED    "\033[41m"
#define BG_YELLOW "\033[43m"
#define BG_EMPTY  "\033[47m"  // white/gray
#define RESET     "\033[0m"


int play_game(int rows, int cols, int board[rows][cols], int height[cols]);
int make_play(int rows, int cols, int height[cols]);
int check_win(int rows, int cols, int board[rows][cols]);
void render(int rows, int cols, int board[rows][cols]);



#endif