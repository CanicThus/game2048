#ifndef GAME2048_H
#define GAME2048_H

#include "game2048.h"
#include "tools.h"
#include <getch.h>
#include <stdlib.h>
#include <time.h>
#include "direction.h"

bool is_moved=true;
int (*view)[4]=NULL;
//初始化
void init()
{
	debug("%s\n",__func__);
	
	view =malloc(sizeof(view[0][0])*4*4 );
	srand(time(NULL));
	
}
	//申请堆内存,加载数据
//启动函数
void start()
{
	debug("%s\n",__func__);
	for(;;)
	{
		rand_two();
		show();
		is_moved=false;
		switch(getch())
		{
			case 183: up();break;
			case 184: down();break;
			case 186: left();break;
			case 185: right();break;
		}
		if(is_over()) return;
	}	
}
	//1.随机产生2
	//4. 判断是否结束
	//2.显示界面
	//3.获取方向键处理
	
//结束函数
void end_game()
{
	debug("%s\n",__func__);	
	free(view);
	view=NULL;
	
}
	//保存数据/写入文件，释放堆内存
#endif//GAME2048_H
