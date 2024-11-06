#ifndef _ALL_H_
#define _ALL_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define END 4
#define TIME_SLEEP 10000

typedef struct Body{
	int x;
	int y;
}bdy;

unsigned int data[29][19];
bdy head;
bdy tail;
bdy sweet;
int marck;
int speed; 

bdy radm_pos(){
	bdy pos;
	pos.x = rand()%29 + 1;
	pos.y = rand()%19 + 1;
	return pos;
}

void gotoxy(int x, int y) {
	COORD position = { x,y };
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hWnd, position);
}

void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); 
}

#endif
