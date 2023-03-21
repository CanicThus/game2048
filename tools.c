#include "tools.h"
#include "game2048.h"
#include <stdlib.h>
#include "direction.h"

bool is_full()//static 仅本文件使用
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{	
			if(view[i][j]==0)
			{
				  return false;
			}
		}
	}
	return true;
}
void rand_two()
{
	debug("%s\n",__func__);
	if(is_full())
	{
		debug("没有空位\n");
		return;
	}
	for(;is_moved;)
	{
		int x=rand()%4;
		int y=rand()%4;
		if(view[x][y]==0)
		{
			view[x][y]=2;
			return;
		}
	}
}
void show()
{
	
	debug("%s\n",__func__);
	system("clear");
	for(int i=0;i<4;i++)
	{
		printf("--------------------\n");
		
			for(int j=0;j<4;j++)
			{
				
				if(view[i][j])
				{
					printf("|%4d",view[i][j]);
				}
				else printf("|    ");
			}
			printf("|\n");
		
	}
	printf("--------------------\n");
}
bool is_over()
{
	debug("%s\n",__func__);
	if(!is_full()) return false;
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(view[x][y]==view[x][y+1]) return false;
		}
	}
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(view[y][x]==view[y+1][x]) return false;
		}
	}
	return true;
}

