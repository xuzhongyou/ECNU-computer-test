#include <stdio.h>
#include <stdlib.h>
int  deal(long long int k);
int *flag;

int main(int argc, char *argv[])
{

	flag=(int *)malloc(3000001*sizeof(int));
	long int i,j;
	int maximum;
	int start;
	int end;
	int temp;
	flag[0] = 0;
	flag[1] = 1;
	for(i = 2;i<1000001;i++){
		flag[i] = 0;
		deal(i);
	}
	while(scanf("%d %d",&i,&j)!=EOF){
		(i>j)?(start = j,end = i):(start = i,end = j);
        maximum = 0;
		for(;start<=end;start++){
			temp = flag[start];
			if(maximum < temp){
				maximum = temp;
			}
		}
		printf("%d %d %d\n",i,j,maximum);
	}
	
//	system("pause");
	return 0;
}

int deal(long long int x)
{
	if(x == 0){
		return 0;
	}
    if (x>1000000)
	{
		if ((x & 1) ==0) return deal(x>>1)+1; // 偶数
		else return deal(3*x+1)+1;  //奇数
	}
	else{
		int ans;
		if (flag[x] !=0)
			return flag[x];
		if ((x & 1)==0){ // 偶数
			ans=deal(x>>1)+1;
		}
		else//奇数
			ans=deal(3*x+1)+1;
		flag[x]=ans;
		return ans;
	}
		
}
