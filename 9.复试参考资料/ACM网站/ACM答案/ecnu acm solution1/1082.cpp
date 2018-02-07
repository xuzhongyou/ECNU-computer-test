#include <iostream>
using namespace std;

int jie[10];

void init()
{
	jie[0]=1;
	for (int i=1;i<=9;++i) jie[i]=jie[i-1]*i;
}

int N;

void deal()
{
	if (N==0) 
	{
		printf("NO\n");
		return ;
	}

	for (int i=9;i>=0;--i) if (N>=jie[i]) N-=jie[i];
	
	if (N==0)
		printf("YES\n");
	else 
		printf("NO\n");
}

int main()
{
	init();

	while (scanf("%d",&N))
	{
		if (N<0) break;
		deal();
	}

	return 0;
}
