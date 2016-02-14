#include <stdlib.h>
#include <ncurses.h>

#include "output.h"

void updateStatus(int gold){
	int ymax, xmax;
	int ypos, xpos;
	getyx(stdscr, ypos, xpos);
	getmaxyx(stdscr, ymax, xmax);
	mvprintw(ymax-1, 0, "GOLD: %d", gold);
	mvprintw(ymax-2, 0, "%2d,%2d", xpos, ypos);
	move(ypos, xpos);
}

void endGame(int goldFinal){
	nocbreak(); //ERROR?
	refresh();
	endwin();
	if (goldFinal == 0){
		printf("Pressed q: END GAME\n");
	} else {
		printf("You have accumulated %d gold!\n", goldFinal);
	}
	exit(1);
}
