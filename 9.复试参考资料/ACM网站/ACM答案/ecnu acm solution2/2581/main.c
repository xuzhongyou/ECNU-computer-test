#include <stdio.h>
#include <stdlib.h>

void
binarycount(int m,int *zero,int *one);
int main(int argc, char *argv[]) 
{
	int m,n;
	int zero,one;
	scanf("%d",&n);
	while(n--){
        zero = 0;
		one = 0;
		scanf("%d",&m);
		binarycount(m,&zero,&one);
		printf("%d %d\n",zero,one);
	}
	system("pause");	
	return 0;
}

void
binarycount(int m,int *zero,int *one){
	while(m/2 !=0){
		if(m%2 == 0){
			(*zero)++;
		}
		if(m%2 ==1){
            (*one)++;
		}
		m = m/2;
	}
	(*one)++;
	
}
