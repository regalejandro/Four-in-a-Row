/*********************************************************
 * File: settings.c
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Controls game settings
 * 
 * Date Created: April 13, 2026
 * 
*********************************************************/

#include <termios.h>
#include <unistd.h>

#include "settings.h"

const GameRules CONNECT4 = {6, 7, 4};
const GameRules CONNECT5 = {8, 9, 5};



void enableRawMode(struct termios *old_tio) {
    struct termios new_tio;

    tcgetattr(STDIN_FILENO, old_tio);   // save current settings
    new_tio = *old_tio;

    new_tio.c_lflag &= ~(ICANON | ECHO); // disable buffering + echo

    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void disableRawMode(struct termios *old_tio) {
    tcsetattr(STDIN_FILENO, TCSANOW, old_tio);
}