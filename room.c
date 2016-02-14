#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "setup.h"
#include "room.h"

void printRec(int y, int x, int height, int width){
	//CREATES THE LEVELS
	for (int i=y-1; i<(height-(height-width)+y+1); i++){
		mvaddch(i, x-1, '|'); //West wall
		for (int j=0; j<height+1;j++){
			mvaddch(i,x+j,'.');
		}
		mvaddch(i, (x+height+1), '|'); //East wall
	}
	for (int i=x-1; i<=(width-(width-height)+x+1); i++){
		mvaddch(y-1, i, '-'); //North wall
		mvaddch((y+width+1), i, '-'); //South wall
	}
	
	//ITEM CONFIG
	int goldnum = 4;
	for(int i=0; i<goldnum; i++){
		//getRandom(&y, &x); // TEST purposes
		mvaddch(rand()%height+y, rand()%width+x, '8'); // TEST purposes
	}
	mvaddch(rand()%height+y, rand()%width+x, '<'); // TEST purposes
		
	//getRandom(&y, &x); // TEST purposes
	mvaddch(rand()%height+y,rand()%width+x, HERO);
	getyx(stdscr, y, x);
	move(y, x-1);
}

Room* configRoom(char* roomDescrip){
	char* test;
	strcpy(test, roomDescrip);
	
	if(roomDescrip[strlen(roomDescrip)] == '\n'){//newline removal
		roomDescrip[strlen(roomDescrip)] = '\0';
	}
		
	for(int i=0; i<strlen(test);i++){
		switch(test[i]){
			
		}
	}
	//printf("TEST: %s\n", test);
}