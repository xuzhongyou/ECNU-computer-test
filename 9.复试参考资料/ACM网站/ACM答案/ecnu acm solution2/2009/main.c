#include <stdio.h>
#include <stdlib.h>
int flag[100001] = {0};
int main(int argc, char *argv[]) 
{

	int m;
	int n;
	int number;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&number);
        flag[number] = -1;
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&number);
		if(flag[number] ==-1){
			printf("yes!\n");
		}else{
			printf("no!\n");
		}
		
	}
	return 0;
}
