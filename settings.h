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


#ifndef SETTINGS_H
#define SETTINGS_H

extern const GameRules CONNECT4;
extern const GameRules CONNECT5;

typedef struct {
	int rows;
	int cols;
	int win_num;
} GameRules;


void enableRawMode(struct termios *old_tio);
void disableRawMode(struct termios *old_tio);

#endif