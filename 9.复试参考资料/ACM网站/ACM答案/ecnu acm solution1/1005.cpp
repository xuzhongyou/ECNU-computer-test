#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct order
{
	int PID;
	int TIME;
}o[2000];

int last[2000];
int os;
int NUM;
int t;
int cases;

void init()
{
	char temp[100];
	os=0;
	while (true)
	{
		scanf("%s",temp);
		if (strcmp(temp,"EndRegister")==0) break;
		scanf("%d%d",&o[os].PID,&o[os].TIME);
		os++;
	}
	scanf("%s%d",temp,&NUM);

	t=0;
	int i,j,k;
	int min;
	for (i=0;i<os;++i)
		last[i]=1;
	
	printf("test case %d:\n",cases);
	for (i=1;i<=NUM;++i)
	{
		min=999999999;
		k=0;
		for (j=0;j<os;++j)//如果一次for遍历没有找到可以执行的，那么继续执行原来的PID，
		{
			if (last[j]*o[j].TIME<min || last[j]*o[j].TIME==min && o[j].PID<o[k].PID)
				{min=last[j]*o[j].TIME ;k=j;}//如果找到一个可以执行的，则一定要找到TIME 最小的一个。
		}
		last[k]++;
		printf("%d\n",o[k].PID);
	}
	printf("\n");
}

int main()
{
	int i;
	cin>>i;
	for (cases=1;cases<=i;++cases) init();

	return 0;
}



