#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include<stdbool.h>	
#ifdef DEBUG 
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...)
#endif
	
#define error(...) printf("%s %s:%d %s %m %s %s \n",__FILE__,__func__,__LINE__,__VA_ARGS__,__DATE__,__TIME__)

	
void rand_two();
void show();
bool is_over();
bool is_full();
#endif//TOOLS_H
