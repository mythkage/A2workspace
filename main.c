#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>// TEST purposes

#include "setup.h"
#include "output.h"
#include "room.h"

/*
NEXT STEP:
	PARSING FILE
	END GAME INTERACTION < >
*/

/* HEADERS */

void printMsg(const char* msg); //CHECK USAGE
void getRandom(int* y, int* x); //CHECK USAGE
/* FUNCTION START */

void printMsg(const char* msg){// TEST purposes
	int x, y;
	getyx(stdscr, y, x);
	mvprintw(0,0,msg);
	move(y,x);
}

void getRandom(int* y, int*x){// TEST purposes
	int ymax, xmax;
	getmaxyx(stdscr, ymax, xmax);
	*y = rand()%(ymax-2)+2;
	*x = rand()%xmax;
}

/* FUNCTION END */

int main (int argc, char* argv[]){
	FILE* level;
	char buffer[256];
		
	Room* heapRoom;
	heapRoom = malloc(sizeof(Room)*6);
	
	level = fopen(argv[1],"r");
	
	srand(time(NULL));// TEST purposes
	
	while(fgets(buffer,256,level)!=NULL){
		printf("%s",buffer); //This just ensures it reads the lines
		//configRoom(buffer);//parse in line by line via ConfigRoom
	}
	printf("\n");
	
	if (!level){
		printMsg("\nLevel file could not be opened\n");
		return 0;
	}
	
	fclose(level);
	
	startGame();
	//mvprintw(21, 0, "Last line on file: %s", buffer);
	gamePlay();
	//endGame();
	
	return 0;
}
