#include <stdio.h>
#include <stdlib.h>
//ÎÞ·¨AC
int main(int argc, char *argv[]) 
{
	int number;
	int i=2;
	while(scanf("%d",&number)!=EOF){
		for(i = 2;i<=number/2;i++){
			if(number%i == 0){
				printf("%d %d\n",number/i,i);
				break;
			}
		}
	}
	system("pause");
	return 0;
}

