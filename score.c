#include "all.h"

int _max();
int save(int num);
int score(int opt);
void create_sweet();
void keyhandle(int key, int ift);

int _max(){
	int num;
	FILE *fr;
	fr = fopen("marck.txt", "r");
	fscanf(fr, "%d",&num);
	fclose(fr);
	return num;
}

int save(int num){
	FILE *fw;
	fw = fopen("marck.txt", "w");
	fprintf(fw, "%d",num);
	fclose(fw);
}

int score(int opt){
	switch(opt){
		case 'w':
			if(data[head.x - 1][head.y - 2] == -1){
				data[head.x - 1][head.y - 2] = 0;
				if(speed < 7000)
					speed += 100;
				return 0;
			}
			else
				return 1;
			break;
		case 's':
			if(data[head.x - 1][head.y] == -1){
				gotoxy(0,21);
				data[head.x - 1][head.y] = 0;
				if(speed < 7000)
					speed += 100;
				return 0;
			}	
			else
				return 1;
			break;
		case 'a':
			if(data[head.x - 2][head.y - 1] == -1){
				data[head.x - 2][head.y - 1] = 0;
				if(speed < 7000)
					speed += 100;
				return 0;
			}
			else
				return 1;
			break;
		case 'd':
			if(data[head.x][head.y - 1] == -1){
				data[head.x][head.y - 1] = 0;
				if(speed < 7000)
					speed += 100;
				return 0;
			}
			else
				return 1;
			break;
	}
}

void create_sweet(){
	int num;
	int crt;
	crt = rand()%10;
	if(crt == 0)
		for(num = 0; num<3; num++){
			sweet = radm_pos();
			if(!data[sweet.x - 1][sweet.y - 1]){
				gotoxy(2*sweet.x, sweet.y);
				printf("\033[36m¡ö \033[0m");
				data[sweet.x - 1][sweet.y - 1] = -1;
				break;
			}
		}
}

void keyhandle(int key, int ift){
	int x,y;
	x=63;
	y=15;
	gotoxy(x + 2,y + 0);
	printf("¡ü");
	gotoxy(x + 0,y + 1);
	printf("¡û");
	gotoxy(x + 4,y + 1);
	printf("¡ú");
	gotoxy(x + 2,y + 2);
	printf("¡ý");
	gotoxy(x + 2,y + 1);
	printf("¡ó");
	if(key == 0)
		return;
	switch(key){
		case 'w':
			gotoxy(x + 2,y + 0);
			if(ift)
				printf("\033[32m¡õ\033[0m");
			else
				printf("\033[31m¡õ\033[0m");
			usleep(110000);
			gotoxy(x + 2,y + 0);
			printf("¡ü");
			break;
		case 's':
			gotoxy(x + 2,y + 2);
			if(ift)
				printf("\033[32m¡õ\033[0m");
			else
				printf("\033[31m¡õ\033[0m");
			usleep(110000);
			gotoxy(x + 2,y + 2);
			printf("¡ý");
			break;
		case 'a':
			gotoxy(x + 0,y + 1);
			if(ift)
				printf("\033[32m¡õ\033[0m");
			else
				printf("\033[31m¡õ\033[0m");
			usleep(110000);
			gotoxy(x + 0,y + 1);
			printf("¡û");
			break;
		case 'd':
			gotoxy(x + 4,y + 1);
			if(ift)
				printf("\033[32m¡õ\033[0m");
			else
				printf("\033[31m¡õ\033[0m");
			usleep(110000);
			gotoxy(x + 4,y + 1);
			printf("¡ú");
			break;
		case ' ':
			gotoxy(x + 2,y + 1);
			printf("\033[32m¡ó\033[0m");
			usleep(110000);
			gotoxy(x + 2,y + 1);
			printf("¡ó");
			break;
		default:
			gotoxy(x + 2,y + 1);
			printf("\033[31m¡ó\033[0m");
			usleep(110000);
			gotoxy(x + 2,y + 1);
			printf("¡ó");
			break;
	}
}
