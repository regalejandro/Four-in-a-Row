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

int mode = CPU;
GameRules ruleset = CONNECT4;

void handle_args(int argc, char* argv[]) {

	if (argc == 1) {
		return;
	}

	if (argc > 3) {
		perror("Too many arguments.\n");
		exit(1);
	}

	for (int n = 1; n < argc; n++) {
		if (strcmp(argv[n], "3") == 0)
			ruleset = CONNECT3;
		else if (strcmp(argv[n], "4") == 0)
			ruleset = CONNECT4;
		else if (strcmp(argv[n], "5") == 0)
			ruleset = CONNECT5;
		else if (strcmp(argv[n], "6") == 0)
			ruleset = CONNECT6;
		else if (strcmp(argv[n], "pvp") == 0)
			mode = PVP;
		else if (strcmp(argv[n], "cpu") == 0)
			mode = CPU;
		else {
			printf("Argument '%s' not a valid argument\nEnter 'pvp' or 'cpu' for gamemode\nEnter a number for win condition (3, 4, 5, 6)\n", argv[n]);
			exit(2);
		}
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

