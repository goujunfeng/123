#include "all.h"
#include "move.c"
#include "score.c"

//��������
extern int marck; 
//�������� 
extern bdy radm_pos();
extern void hidecursor(); 
extern void gotoxy(int x, int y);
//move.c���� 
extern int permission_key(int opt, int key);
extern int permission_opt(int opt);
extern void move_head(int opt);
extern void move_tail();
//score.c���� 
extern int _max();
extern int save(int num);
extern int score(int opt);
extern void create_sweet();
extern void keyhandle(int key, int ift);

int main(){
	void farem(); 		
	void game_start(int num);	
	hidecursor();		//���ع�� 
	farem();			//���Ʊ߿� 
	game_start(_max());		//��ʼ��Ϸ 
}

void farem(){	//���Ʊ߿� 
	int x,y;
	gotoxy(63,3);
	printf("�÷֣�");
	gotoxy(63,7);
	printf("MAX��");
	for(y = 0; y < 21; y++)
		if(y == 0){
			gotoxy(0,y);
			for(x = 0; x < 36; x++)
				printf("�� ");
		}
		else if(y == 20){
			gotoxy(0,y);
			for(x = 0; x < 36; x++)
				printf("�� ");
		}
		else if(y == 12){
			gotoxy(0,y);
			printf("��");
			gotoxy(60,y);
			for(x = 0; x < 6; x++)
				printf("�� ");
		}
		else{
			gotoxy(0,y);
			printf("��");
			gotoxy(60,y);
			printf("��");
			gotoxy(70,y);
			printf("��");
		}
} 

void game_start(int num){//��ʼ��Ϸ 
	int tm;
	int key;
	int opt;
	int pms_key;
	int scr = 1;
	time_t tim;
	void sub();
	void key_opt(int *key);
	system("title ̰����"); 
	system ("mode con cols=80 lines=21");	//�ı�������Ĵ�С 
	hidecursor();							//���ع�� 
	srand(time(&tim));
	head = radm_pos();
	tail = head;
	data[head.x - 1][head.y - 1] = 4;
	speed = 0;
	marck = 0;
	farem(); 
	keyhandle(0, 0);
	while(1){
		tm = TIME_SLEEP - speed;						//���� 
		if(!scr)
			marck += 10;
		gotoxy(63,5); 
		printf("%5d",marck);
		gotoxy(63,9); 
		if(marck > num)
			num = marck;
		printf("%5d",num);
		if(scr == 1)
			move_tail();								//�ƶ�β�� 
		scr = 1;
		move_head(opt);									//�ƶ�ͷ�� 
		sub();
		while(tm--)
			if(_kbhit())								//�ж��Ƿ��а������� 
				if(key = _getch()){						//ʵ�ְ������� 
					if(key == 224)
						key = _getch();
					key_opt(&key);
					pms_key = permission_key(opt,key);		//�жϲ����Ϸ��� 
					if(pms_key)								 
						opt = key;							//ִ�в���
					keyhandle(key, pms_key);				//�������� 
					if(pms_key)
						break;
				}
		scr = score(opt);								//�÷��ж� 
		if(!permission_opt(opt))						//�Ϸ����ж� 
			break;
		create_sweet(opt);								//���ɵ÷ֵ� 
	}
	save(num);
}

void key_opt(int *key){
	switch(*key){
		case 72:
		case 87:
		case 119:
			*key = 'w';
			break;
		case 80:
		case 83:
		case 115:
			*key = 's';
			break;
		case 65:
		case 75:
		case 97:
			*key = 'a';
			break;
		case 68:
		case 77:
		case 100:
			*key = 'd';
			break;
	}
}

void sub(){
	int x, y;
	if(data[tail.x - 1][tail.y - 1] == 20)
		for(x = 0; x < 29; x++){
				for(y = 0; y < 19; y++)
					if(data[x][y] != 0 && data[x][y] != -1)
						data[x][y] -= 10;
		}
}
