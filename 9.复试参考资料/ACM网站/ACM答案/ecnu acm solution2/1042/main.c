#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int cost[7];
int kind[7] = {100,50,20,10,5,2,1};
int main(int argc, char *argv[]) 
{

	int n,money,i;
	scanf("%d",&n);
	while(n--){
		memset(cost,0,sizeof(int)*7);
		scanf("%d",&money);
		zhaoqian(money);
		i = 0;
		for(i =0;i<7;i++){
			printf("%d",cost[i]);
			if(i!=6){
				printf(" ");
			}else printf("\n");
		}
	}
	system("pause");	
	return 0;
}
void
zhaoqian(int money){
	int i = 0;
	for(i = 0;i<7;i++){
		if(money>=kind[i]){
			cost[i] = money/kind[i];
			money = money%kind[i];
		}
	}

}
