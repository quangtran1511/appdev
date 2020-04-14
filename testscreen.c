#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"

int main(void)
{
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
	senddata(poststr, URL);
	setcursor(1,1);
	printf("Screen size,ROW-%d, COL-%d\n", cur.row, cur.col);
	printf("HTTP post is sent to %s\n", URL);
	getchar();	// waiting for users to press a key
	for(int i=0; i<cur.row; i++){
		setcolor(RED, GREEN);
		clearscreen();
		float step = (float)cur.col/cur.row;
		setcursor(i+1,step*i+1);
		printf("HELLO\n");
		usleep(500000);
	}
/*	for(int i=1; i<10; i++){
        setcolor(RED, GREEN);
        clearscreen();
        setcursor(i*2, 40);
        printf("HELLO\n");
        usleep(500000);
    }
	for(int i=0; i<20; i++){
        setcolor(RED, GREEN);
        clearscreen();
        setcursor(20, 40-i*2);
        printf("HELLO\n");
        usleep(500000);
    }
for(int i=0; i<10; i++){
        setcolor(RED, GREEN);
        clearscreen();
        setcursor(20-i*2, 1);
        printf("HELLO\n");
        usleep(500000);
    }*/
/*	 for(int i=0; i<19; i++){
        setcolor(GREEN, BLACK);
        clearscreen();
        setcursor(19-i, i*2);
		printf("HELLO\n");
		setcolor(RED, BLACK);
		setcursor(i, i*2);
		box();
		setcursor(12, 34);
   		setfgcolor(MAGENTA);
   		printf("e1900293\n");
        usleep(500000);
    }
	 for(int i=0; i<19; i++){
        setcolor(GREEN, BLACK);
        clearscreen();
        setcursor(i, 36+i*2);
        printf("HELLO\n");
		setcolor(RED, BLACK);
		setcursor(19-i, 36+i*2);
		box();
		setcursor(12, 34);
		setfgcolor(MAGENTA);
		printf("e1900293\n");
        usleep(500000);
    }*/

//	printf("the message will displayed in BLUE code\n");
	setcursor(12, 34);
	setfgcolor(MAGENTA);
	printf("e1900293\n");
/*	getchar();
	drawbar(30, 30);
	drawbar(50, 30);*/

	getchar();
	resetcolor();
	clearscreen();
	printf("This line is back to default color\n");
}
