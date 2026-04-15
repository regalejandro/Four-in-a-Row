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

#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct {
	int rows;
	int cols;
	int win_num;
} GameRules;

extern const GameRules CONNECT4;
extern const GameRules CONNECT5;

extern GameRules ruleset;

void enableRawMode(struct termios *old_tio);
void disableRawMode(struct termios *old_tio);

#endif