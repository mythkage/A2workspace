#include <stdlib.h>
#include <ncurses.h>

#include "output.h"
#include "setup.h"
#include "move.h"

void moveCursor(char input, int* gold){
	int x, y;
	int oldx, oldy;
	char atPos;
	getyx(stdscr, y, x);
	oldx = x; oldy = y;
	atPos = mvinch(y, x);
	
	//CLEAR MSG TEST purposes
	getyx(stdscr, y, x);
	move(0,0);
	clrtoeol();
	move(y,x);
	
	switch(input){
		case 'w':
			y--;
			break;
		case 'a':
			x--;
			break;
		case 's':
			y++;
			break;
		case 'd':
			x++;
			break;
		default:
			break;
	}
	
	//collision log
	if(!checkCollision(&atPos, y, x)){
		mvaddch(y, x, HERO);
		mvaddch(oldy, oldx, ' ');
		move(y, x);
	} else if (atPos == '-' || atPos == '|') {
		/* OBSTRUCTIONS */
		mvprintw(0, 0, "Collision with %c OBSTRUCTIONS", atPos);
		move(oldy, oldx);
	} else {
		/* INTERACTION */
		mvprintw(0, 0, "Collision with %c INTERACTIONS", atPos);
		switch (atPos){
			case '*':
				*gold += rand()%51;
				//mvprintw(0, 0, "GOLD: %d", *gold);// TEST purposes
				break;
			case '8':
				*gold += rand()%201+50;
				break;
			case '<':
			case '>':
				endGame(*gold);
				break;
			default:
				break;
		}
		mvaddch(y, x, HERO);
		mvaddch(oldy, oldx, '.');
		move(y, x);
	}
}

int checkCollision(char* c, int y, int x){
	int tempx,tempy;
	getyx(stdscr, tempy, tempx);
	*c = mvinch(y, x);
	if(*c == ' '){
		return 0;
	} else {
		return 1;
	}
}
