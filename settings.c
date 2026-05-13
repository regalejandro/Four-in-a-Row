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



#include "settings.h"

const GameRules CONNECT3 = {5, 5, 3};
const GameRules CONNECT4 = {6, 7, 4};
const GameRules CONNECT5 = {8, 9, 5};
const GameRules CONNECT6 = {9, 11, 6};

GameRules ruleset = {0};


void handle_args(int argc, char* argv[]) {

	if (argc > 1) {

		char* arg2 = argv[1];

		if (strcmp(arg2, "3") == 0)
			ruleset = CONNECT3;
		else if (strcmp(arg2, "4") == 0)
			ruleset = CONNECT4;
		else if (strcmp(arg2, "5") == 0)
			ruleset = CONNECT5;
		else if (strcmp(arg2, "6") == 0)
			ruleset = CONNECT6;
		else {
			printf("Argument '%s' not a valid win condition\n", arg2);
			exit(2);
		}
	}
	else if (argc > 2) {
		perror("Incorrect number of arguments.\n");
		exit(1);
	}
	else {
		ruleset = CONNECT4;
	}


}

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

