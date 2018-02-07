#include <iostream>
using namespace std;

int C;
int a1,a2,a3,a4;
int t1,t2,t3,t4;
int ans1,ans2,ans3,ans4;
int ans;

void init()
{
	ans=9999;
	
	if (a1>4) a1=4;
	if (a2>10) a2=10;
	if (a3>20) a3=20;
	if (a4>100) a4=100;

	for (t1=0;t1<=a1;++t1)
		for (t2=0;t2<=a2;++t2)
			for (t3=0;t3<=a3;++t3)
				for (t4=0;t4<=a4;++t4)
					if (t1*25+t2*10+t3*5+t4==C && t1+t2+t3+t4<ans)
					{
						ans=t1+t2+t3+t4;
						ans1=t1;ans2=t2;ans3=t3;ans4=t4;
					}

	if (ans==9999) 
	{
		printf("Cannot dispense the desired amount.\n");
		return;
	}

	printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",ans1,ans2,ans3,ans4);
	return;
}


int main()
{
	while (scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&C)==5)
	{
		if (a1==0 && a2==0 && a3==0 && a4==0 && C==0) break;
		init();
	}
	return 0;
}

