#include <stdio.h>
#include <stdlib.h>
/*
Description

Castor在ECNU工厂工作。总厂有一条生产线，现在生产流水线上排队的零件总数为M。当前Castor开始加工第一个零件。
流水线上的零件总是按顺序加工的。例如零件i必须是在零件i+1之前加工.
现在Castor只需要再加工K(K<=M)个零件就能休息了，Castor想知道他还要工作多长时间才能休息.
Input

第一行为一个整数T,表示测数数据的组数.
对每组测试数据
第一行有两个整数M,K(1<=K<=M<=1000)
然后一行有M个数字 第i个数字表示零件队列的第i个零件需要加工的时间为ti(1<=ti<=10000)
Output

每组数据输出一行,每行只有一个整数表示Castor还需要工作多长时间

Sample Input

2
3 2
5 2 3
3 1
1 2 3
Sample Output

7
1
*/
int main(int argc, char *argv[]) 
{
	int T,M,K;
	int count;
	int i;
	int sum;
	scanf("%d",&T);
	while(T--){
		sum = 0;
		scanf("%d %d",&M,&K);
		count = M - K;
		//printf("%d",count);
		while(K--){
			scanf("%d",&i);
			sum+=i;
		}
		while(count--){
			scanf("%d",&i);
			//printf("--%d--",i);
		}
		printf("%d\n",sum);
	}
	//system("pause");
	return 0;
}
