/*********************************************************
 * File: settings.h
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Defines game settings
 * 
 * Date Created: April 13, 2026
 * 
*********************************************************/

#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef SETTINGS_H
#define SETTINGS_H

#define CPU 0
#define PVP 1

typedef struct {
	int rows;
	int cols;
	int win_num;
} GameRules;

extern const GameRules CONNECT3;
extern const GameRules CONNECT4;
extern const GameRules CONNECT5;
extern const GameRules CONNECT6;

extern GameRules ruleset;
extern int mode;

void handle_args(int argc, char* argv[]);
void enableRawMode(struct termios *old_tio);
void disableRawMode(struct termios *old_tio);

#endif