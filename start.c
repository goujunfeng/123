#include "all.h"
#include "move.c"
#include "score.c"

//公共变量
extern int marck; 
//公共函数 
extern bdy radm_pos();
extern void hidecursor(); 
extern void gotoxy(int x, int y);
//move.c函数 
extern int permission_key(int opt, int key);
extern int permission_opt(int opt);
extern void move_head(int opt);
extern void move_tail();
//score.c函数 
extern int _max();
extern int save(int num);
extern int score(int opt);
extern void create_sweet();
extern void keyhandle(int key, int ift);

int main(){
	void farem(); 		
	void game_start(int num);	
	hidecursor();		//隐藏光标 
	farem();			//绘制边框 
	game_start(_max());		//开始游戏 
}

void farem(){	//绘制边框 
	int x,y;
	gotoxy(63,3);
	printf("得分：");
	gotoxy(63,7);
	printf("MAX：");
	for(y = 0; y < 21; y++)
		if(y == 0){
			gotoxy(0,y);
			for(x = 0; x < 36; x++)
				printf("■ ");
		}
		else if(y == 20){
			gotoxy(0,y);
			for(x = 0; x < 36; x++)
				printf("■ ");
		}
		else if(y == 12){
			gotoxy(0,y);
			printf("■");
			gotoxy(60,y);
			for(x = 0; x < 6; x++)
				printf("■ ");
		}
		else{
			gotoxy(0,y);
			printf("■");
			gotoxy(60,y);
			printf("■");
			gotoxy(70,y);
			printf("■");
		}
} 

void game_start(int num){//开始游戏 
	int tm;
	int key;
	int opt;
	int pms_key;
	int scr = 1;
	time_t tim;
	void sub();
	void key_opt(int *key);
	system("title 贪吃蛇"); 
	system ("mode con cols=80 lines=21");	//改变输出区的大小 
	hidecursor();							//隐藏光标 
	srand(time(&tim));
	head = radm_pos();
	tail = head;
	data[head.x - 1][head.y - 1] = 4;
	speed = 0;
	marck = 0;
	farem(); 
	keyhandle(0, 0);
	while(1){
		tm = TIME_SLEEP - speed;						//加速 
		if(!scr)
			marck += 10;
		gotoxy(63,5); 
		printf("%5d",marck);
		gotoxy(63,9); 
		if(marck > num)
			num = marck;
		printf("%5d",num);
		if(scr == 1)
			move_tail();								//移动尾部 
		scr = 1;
		move_head(opt);									//移动头部 
		sub();
		while(tm--)
			if(_kbhit())								//判断是否有按键操作 
				if(key = _getch()){						//实现按键操作 
					if(key == 224)
						key = _getch();
					key_opt(&key);
					pms_key = permission_key(opt,key);		//判断操作合法性 
					if(pms_key)								 
						opt = key;							//执行操作
					keyhandle(key, pms_key);				//按键反馈 
					if(pms_key)
						break;
				}
		scr = score(opt);								//得分判断 
		if(!permission_opt(opt))						//合法性判断 
			break;
		create_sweet(opt);								//生成得分点 
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
