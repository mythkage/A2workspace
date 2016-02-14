#include <stdlib.h>
#include <ncurses.h>

#include "move.h"
#include "output.h"
#include "room.h"
#include "setup.h"

void startGame(){
	int y, x;
	
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	
	move(2,2);
	getyx(stdscr, y, x);
	
	printRec(10,8,14,12);
	printRec(26,8,14,12);
}

void gamePlay(){
	char input;
	int gold;// TEST purposes
	gold = 0;
	//mvprintw(2, 0, "GOLD: %d", gold);
	while(input != 'q'){
		input = getch();
		moveCursor(input, &gold);
		updateStatus(gold);
	}
	endGame(gold);
	
}
