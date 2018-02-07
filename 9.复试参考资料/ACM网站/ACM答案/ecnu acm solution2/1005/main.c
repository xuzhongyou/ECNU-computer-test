#include <stdio.h>
#include <stdlib.h>
/*
解题思路：
*/
typedef struct PROCESS{
	int PID;
	int TIME;
}PROCESS;


void init(int N){
	PROCESS temp[10000];
	char flag[100];
	int count = 0;
	int run;
	int i;
	while(1){
        scanf("%s",&flag);
		if(strcmp(flag,"EndRegister") ==0) break;
		else{
			scanf("%d %d",&temp[count].PID,&temp[count].TIME);
			count++;
		}
	}
	scanf("%s %d",&flag,&run);
	int last[10000];
	for(i = 0;i<count;i++){
		last[i] = 1;
	}
	printf("test case %d:\n",N);
	
	for(i = 0;i<run; i++){
        int min = 99999999;
		int j = 0;
		int k = 0;
		for(j = 0;j<count;j++){
			if(last[j]*temp[j].TIME < min || last[j]*temp[j].TIME == min &&temp[j].PID <temp[k].PID){
				min = last[j]*temp[j].TIME;
				k = j; //j 之后自增;
			}
		}
		last[k]++;
		printf("%d\n",temp[k].PID);

	}
	
	
}

int main(int argc, char *argv[])
{
	int N;
	int i;
	scanf("%d",&N);
	for(i = 1;i<=N;i++){
		init(i);
	}
	system("pause");
	return 0;
}
