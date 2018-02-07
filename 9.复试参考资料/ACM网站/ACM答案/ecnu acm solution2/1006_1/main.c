#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
array[MAX+1] = {0};
int main(int argc, char *argv[]) 
{
	int number_one;
	int number_two;
	int i;
	int k;
	array[1] = 0;
	array[2] = 1;
	for(i = 3;i<=MAX;i+=2){
		array[i] = 1;
	}
	for(i = 3;i<MAX;i+=2){
		if(array[i]){
			k = 2;
			while(i*k<MAX){
				array[i*k] = 0;
				k++;
			}
		}
	}

	while(scanf("%d %d",&number_one,&number_two)!= EOF){
		i = 0;
		while(number_one<=number_two){
			if(array[number_one]){
				i++;
			}
			number_one++;
		}
		printf("%d\n",i);
	}
	return 0;
}
