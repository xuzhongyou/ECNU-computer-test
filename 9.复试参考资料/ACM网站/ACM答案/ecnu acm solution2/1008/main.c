#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int N;
	scanf("%d",&N);
	while((N--)>0){
       	int count = 0;//1 the count of number div 5 remainder 0
		int number;
		scanf("%d",&number);
		for(;number>0;number=number/5)
			count += number/5;
		printf("%d\n",count);
	}
	return 0;
}
