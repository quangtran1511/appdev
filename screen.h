// usually in a header file we have 2 parts:
// 1. function declarations
// 2. constants definitions

// constants definitions
#define ESC 27		//or using hex 0x1B
// make enumeration for fg colors
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)	// this is called macro definition

#define UNICODE
#define BAR "\u2590"
#define BOX "\u2588"

#define DEBUG
// The following is the information of cursor position, this information 
// will be decoded by an escape sequence ESC[6n, and query reply should be a string consisting 
// row and col numbers of the curson
typedef struct{
	int row;
	int col;
}Position;
// making a constant in a name will make your program more readable
// now we can use color names in function setfgcolor()

// function declarations
void setfgcolor(int);
void setbgcolor(int);
void resetcolor(void);
void clearscreen(void);
void setcursor(int, int);
void drawbar(int, int);
void setcolor (int, int);
void box(void);
Position getscreensize(void);		//this functin return a compund data (2 ints)
int devicestatus(void);
