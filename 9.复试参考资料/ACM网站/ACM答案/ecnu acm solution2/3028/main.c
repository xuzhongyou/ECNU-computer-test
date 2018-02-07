#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char* setup(int *array,char *result);
int main(int argc, char *argv[]) 
{
	int array[9];
	int number;
	int i,j;
	char result[100];
	memset(array,0,9*sizeof(int));
	scanf("%d",&number);
	for(j = 0;j<number;j++){
		for(i = 0;i<9;i++){
			scanf("%d",&array[i]);
			//printf("%d",array[i]);
		}
		
		printf("case #%d:\n",j);
        setup(array,result);
		printf("%s\n",result);
	}
	system("pause");
	return 0;
}
char* setup(int *array ,char *result){
	result[0] = '\0';
	int i,j;
	int exp = 9;
	char temp[20];
	int flag = 0;
	for(i = 0;i<9;i++){
		if( array[i]  == 0 ){
			exp--;
		}
		else{
			if(strlen(result) !=0){
	            if(array[i] >0){
	                strcat(result,"+");
				}
			}
			if(i == 8 && strlen(result) !=0){ // 指数为0
				if(array[i] == -1){  // 系数为-1
					strcat(result,"-1");
				}
				else
				strcat(result,itoa(1,temp,10));  // 指数为0 。系数不是-1；
			}else{
                if(array[i] == -1){
					strcat(result,"-");
				}
				else if(array[i] !=1){
					strcat(result,itoa(array[i],temp,10));
				}

				strcat(result,"x");

			}
			
			if(i !=8 && i!=7){
				strcat(result,"^");  // 连接 幂次
				strcat(result,itoa(8-i,temp,10));
				
			}

		}
	}
	if(strlen(result) ==0){
		strcat(result,"0");
	}
	return result;
}

