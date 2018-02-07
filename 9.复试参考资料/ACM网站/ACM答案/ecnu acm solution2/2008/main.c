#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
int number[501];

int main(int argc, char *argv[]) 
{
	int n,m;
	int loc;
	memset(number,0,sizeof(int)*501);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&loc);
		number[loc] = 1;
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&loc);
		if(number[loc]){
			printf("yes!\n");
		}else{
			printf("no!\n");
		}
	}
	system("pause");	
	return 0;
}
