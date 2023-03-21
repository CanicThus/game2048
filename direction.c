#include "tools.h"
#include "direction.h"
#include "game2048.h"

static void copyArray(int array[4][4], int src[4][4])
{
    for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                array[i][j] = src[i][j];
            }
        }
}

static void rotateMatrix(int array[4][4], int count)
{
    int temp[4][4];
        copyArray(temp, array);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                array[i][j] = temp[4 - j - 1][i];
            }
        }
        if (count > 1)rotateMatrix(array, count-1);
}


void up()
{
	debug("%s\n",__func__);
	for(int y=0;y<4;y++)
	{	
		int end=0;
		for(int x=1;x<4;x++)
		{
			for(int i=x;i>end;i--)
			{
				//moved
				if(view[i][y] && view[i-1][y]==0)
				{
					view[i-1][y]=view[i][y];
					view[i][y]=0;
					is_moved=true;
				}
				// add up
				else if(view[i][y] && view[i][y]==view[i-1][y])
				{
					view[i-1][y] *=2;
					view[i][y]=0;
					end=i;
					is_moved=true;
				}
			}
		}
	}
}
void down()
{
	debug("%s\n",__func__);
	rotateMatrix(view, 2);
    up();
    rotateMatrix(view, 2);
	//旋转up
}
void left()
{
	debug("%s\n",__func__);
	rotateMatrix(view, 1);
    up();
    rotateMatrix(view, 3);
}
void right()
{
	debug("%s\n",__func__);
	rotateMatrix(view, 3);
    up();
    rotateMatrix(view, 1);
}
