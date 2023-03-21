#ifndef GAME2048_H
#define GAME2048_H

#include <stdbool.h>
extern int (*view)[4];
extern bool is_moved;
//初始化
void init();
	//申请堆内存,加载数据
//启动函数
void start();
	//1.随机产生2
	//4. 判断是否结束
	//2.显示界面
	//3.获取方向键处理
	
//结束函数
void end_game();
	//保存数据/写入文件，释放堆内存
#endif//GAME2048_H
