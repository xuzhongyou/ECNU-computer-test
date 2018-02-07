#include <stdio.h>
#include <stdlib.h>
#include "math.h"

void
fire();
int main(int argc, char *argv[]) 
{
	fire();
	system("pause");	
	return 0;
}

void
fire(){
	int i= 1000;
	int flag= 1;
	for(i = 1000;i<=9999;i++){
		if(i == biquadrate(i)){
			printf("%d\n",i);
			flag = 0;
		}
	}
	if(flag){
		printf("no answer");
	}
}
int biquadrate(int x){
	int i;
	int sum = 0;
	while(x !=0){
        i =x%10;
		sum += pow(i,4);
		x /=10;
	}
	return sum;
}
