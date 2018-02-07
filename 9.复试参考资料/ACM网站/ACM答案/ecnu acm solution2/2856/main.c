#include <stdio.h>
#include <stdlib.h>
int w,h; // w ÁÐ  h ÐÐ
char array[1001][81];
int main(int argc, char *argv[]) 
{
	system("pause");	
	return 0;
}

int delection(int x,int y){
	if(array[x][y] != '*'){
		return 0;
	}
	if(array[x+1][y] == '*' && array[x][y+1] == '*' && array[x-1])
}
