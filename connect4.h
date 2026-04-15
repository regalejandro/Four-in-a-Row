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


int play_game(int rows, int cols, int board[rows][cols], int height[cols]);
int make_play(int rows, int cols, int height[cols]);
int check_win(int rows, int cols, int board[rows][cols]);
void render(int rows, int cols, int board[rows][cols]);



#endif