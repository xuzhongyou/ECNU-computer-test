#include <iostream>
using namespace std;

int N;
char temp[100];
int times[10];
int len;

int i,j,k;

bool ok[1000000];

void deal()
{
	len=0;

	if (N==0)
	{
		printf("0\n");
		return ;
	}

	if (N==1)
	{
		printf("1\n");
		return ;
	}

	if (!ok[N])
	{
		printf("-1\n");
		return;
	}


	for (i=9;i>=2;--i)
	{
		while (N % i==0)
		{
			N/=i;
			temp[len++]=i;
		}
	}

	if (N>1) 
	{
		ok[N]=false;
		printf("-1\n");
		return;
	}

	for (i=len-1;i>=0;--i) printf("%d",temp[i]);
	printf("\n");
}

int main()
{
	memset(ok,true,sizeof(ok));

	while (scanf("%d",&N))
	{
		deal();
	}

	return 0;
}
