/**
* Eng Zhang Liek
* 
*
*/

#ifndef __ENGZ_ROOM__
#define __ENGZ_ROOM__

typedef struct Room{
	int roomNum; //1-6
	char dimenY; //Max row
	char dimenX; //Max col
	char itemType[10]; //Elements of max 10
	int itemPos[10][10]; //y x pos for the 10 elements
	
	/*
	char z;	char a; // < >
	char g;	char G; // * 8
	char w;	char W; // ) (
	char m;	char M; // ABSZ T
	char e;	char p; // ] !
	*/
} Room;

void printRec(int y, int x, int height, int width);
Room* configRoom(char* roomDescrip);

#endif
