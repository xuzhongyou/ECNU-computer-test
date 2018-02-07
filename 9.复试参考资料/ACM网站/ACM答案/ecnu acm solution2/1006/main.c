#include <stdio.h>
#include <stdlib.h>
#include "math.h"
flag[1000000] = {0};
#define MAX 1000000
void primes();
int prime(int number_one,int number_two);
int main(int argc, char *argv[]) 
{
	int number_one;
	int number_two;
	primes();
	while(scanf("%d%d",&number_one,&number_two)!=EOF){
	printf("%d\n",prime(number_one,number_two));
	}
	return 0;
}

void primes(){

#if 1
	int i,j;
	flag[1]=0;
	for(i=2;i<=MAX;i++)
		flag[i]=1;
	for(i=2;i<=sqrt(MAX);i++)
		if(flag[i])
			for(j=i+i;j<=MAX;j+=i)
				flag[j]=0;
#endif

#if 0
	int i;
	int number;
	flag[1] = 0;
	flag[2] = 1;
	flag[3] = 1;
 	for(number = 5;(number<1000000);number+=2){
		for(i = 2;i<=sqrt(number);i++){
			if(number%i == 0){
				break;
			}
			if((i+1)>sqrt(number)){
				flag[number] = 1;
			}
		}
	}
#endif
}
int prime(int number_one,int number_two){
	int count = 0;
	int i;
	while(number_one<=number_two){
		if(flag[number_one] == 1){
			count++;
		}
		number_one++;
	}
	return count;
}
