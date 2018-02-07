#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int number1,number2;
	int N;
	scanf("%d",&N);
	while(N--){
		while(scanf("%d %d",&number1,&number2) !=EOF){
			printf("%d\n",digit(number1+number2));
		}
	}
	system("pause");	
	return 0;
}
int
digit(int number){
	int count =1;
	while(number/10 !=0){
		count++;
		number /=10;
	}
	return count;
	
	
}
