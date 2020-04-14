//move between files:alt_., alt_,


#include <stdio.h>
#include "screen.h"
// function definition
void setfgcolor(int fg){
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}
void setcolor(int f,int b){
	setfgcolor(f);
	setbgcolor(bg(b));
}

void resetcolor(void){
	printf("%c[0m", ESC);
}

void clearscreen(void){
	printf("%c[2J", ESC);
}

void setcursor(int row,int col){
	printf("%c[%d;%dH", ESC, row, col);
}

void box(void){
	printf("%s%s%s%s\n",BOX , BOX, BOX, BOX);
}

void drawbar(int col, int height){
	int i;
	for(i=1; i<=height; i++)
	{
		setcursor(i, col);
#ifdef UNICODE		// following code are in conditional compilation
		printf("%s", BAR);
#else
		printf("%c", '#');
#endif
	}
}

Position getscreensize(void){
	Position p;
	char ret[100] = "\0";	//	make an empty string for query return
	int r, c;
	setcursor(999, 999);	// move cursor to the right-bottom corner
	printf("%c[6n", ESC);	// send query sequence to the terminal
	scanf("%s", ret);
#ifdef DEBUG
	printf("%s\n", ret);
#endif
#include <string.h>
	// the follwing code will decode the return string from terminal
	if(strlen(ret)>0){
		char dum;		// dummy char to consume the chars in set string
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else{
		p.row = 0;
		p.col = 0;}
	return p;
}

