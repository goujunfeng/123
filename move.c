#include "all.h"

int permission_key(int opt, int key);
int permission_opt(int opt);
void move_head(int opt);
void move_tail();

int permission_key(int opt, int key){
	if(opt == key)
		return 0;
	switch(key){
	 	case 'w':
		 	if(data[head.x - 1][head.y - 2] == 0||data[head.x - 1][head.y - 2] == -1)
		 		return 1;
		 	else
		 		return 0; 
		case 's':
		 	if(data[head.x - 1][head.y] == 0||data[head.x - 1][head.y] == -1)
		 		return 1;
		 	else
		 		return 0;
		case 'a':
		 	if(data[head.x - 2][head.y - 1] == 0||data[head.x - 2][head.y - 1] == -1)
		 		return 1;
		 	else
		 		return 0;
		case 'd':
			if(data[head.x][head.y - 1] == 0||data[head.x][head.y - 1] == -1)
		 		return 1;
		 	else
		 		return 0;
		case ' ':
		 	break;
	}
}

int permission_opt(int opt){
	if(head.x == 30||head.y == 20||head.x == 0||head.y == 0)
		return 0;
	switch(opt){
		case 'w':
			if(data[head.x - 1][head.y - 2] > 0)
				return 0;
			else
				return 1;
			break;
		case 's':
			if(data[head.x - 1][head.y] > 0)
				return 0;
			else
				return 1;
			break;
		case 'a':
			if(data[head.x - 2][head.y - 1] > 0)
				return 0;
			else
				return 1;
			break;
		case 'd':
			if(data[head.x][head.y - 1] > 0)
				return 0;
			else
				return 1;
			break;
	}
}

void move_head(int opt){
	gotoxy(2*head.x, head.y);
	printf("\033[34m¡ö\033[0m");
	switch(opt){
	 	case 'w':
		 	head.y -= 1; 
		 	data[head.x - 1][head.y - 1] = data[head.x - 1][head.y] + 1;
		 	break;
		case 's':
		 	head.y += 1;
		 	data[head.x - 1][head.y - 1] = data[head.x - 1][head.y - 2] + 1;
		 break;
		case 'a':
		 	head.x -= 1; 
		 	data[head.x - 1][head.y - 1] = data[head.x][head.y - 1] + 1;
		 	break;
		case 'd':
		 	head.x += 1;
		 	data[head.x - 1][head.y - 1] = data[head.x - 2][head.y - 1] + 1;
		 	break;
		case ' ':
		 	break;
	}
	gotoxy(2*head.x, head.y);
	printf("\033[33m¡ö \033[0m");
}

void move_tail(){
	int num = data[tail.x - 1][tail.y - 1];
	if(data[head.x - 1][head.y - 1] < 7)
		return;
	gotoxy(2*tail.x - 1, tail.y);
	printf("  ");
	data[tail.x - 1][tail.y - 1] = 0;
	if(num == data[tail.x - 1][tail.y - 2] - 1)
		tail.y -= 1;
	else if(num == data[tail.x - 1][tail.y] - 1)
		tail.y += 1;
	else if(num == data[tail.x - 2][tail.y - 1] - 1)
		tail.x -= 1;
	else if(num == data[tail.x][tail.y - 1] - 1)
		tail.x += 1;
}

