#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int n;
	int i,k;
	int count = 0;
	int gas[1025];
	scanf("%d %d",&n,&k);
	for(i = 0;i<=k;i++){
		scanf("%d",&gas[i]);
		if(getchar() == '\n' ){
			break;
		}
	}
	int dis = 0;
	i = 0;
	while(i<k){
		dis += gas[i];
		if(n<gas[k]){
            printf("No Solution!\n");
		}
		if(n<gas[i]){

            printf("No Solution!\n");
            break;
		}
		if(n<dis){
            printf("No Solution!\n");
            break;
		}
		if(n>=(dis+gas[i+1])){
			i++;
		}
		else{
			count++;
			i++;
			dis = 0;
		}

	}
	printf("%d\n",count);
	system("pause");	
	return 0;
}
