#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define BODY 1.75
int main(int argc, char *argv[]) 
{
	int n;
	while((scanf("%d",&n))&& n!= 0){
		float time;
		float hight;
		if(n<=3){
			hight = 5*(n-1);
		}
		if(n>3){
			hight = 3*(n-3)+10;
		}
		hight+=BODY;
		time = sqrt((2*hight)/9.8);
		printf("%5.3f\n",time);
		
	}
	return 0;
}
