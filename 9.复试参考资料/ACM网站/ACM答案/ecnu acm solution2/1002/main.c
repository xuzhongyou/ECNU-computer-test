#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) 
{
	int N;
	scanf("%d",&N);
	while((N--)>0){
        int array[] = {128,64,32,16,8,4,2,1};
    	int i;
    	char number;
    	short int sum = 0;
       	while((number = getchar())!=EOF && number!='\n')
		   //discard remainder data of buffer
		;
		for(i = 0;i<8;i++){
			sum+= (getchar()-'0')*array[i];
		}
		printf("%d.",sum);
		
		sum = 0;
		for(i = 0;i<8;i++){
			sum+= (getchar()-'0')*array[i];
		}
		printf("%d.",sum);
		
		sum = 0;
		for(i = 0;i<8;i++){
			sum+= (getchar()-'0')*array[i];
		}
		printf("%d.",sum);
		
		sum = 0;
		for(i = 0;i<8;i++){
			sum+= (getchar()-'0')*array[i];
		}
		printf("%d\n",sum);

	}
	return 0;
}
