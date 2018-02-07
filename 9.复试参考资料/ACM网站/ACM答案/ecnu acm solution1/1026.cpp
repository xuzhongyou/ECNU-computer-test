#include <iostream>
#include <cmath>
using namespace std;

double H;
double ans;
int N;

void deal()
{
	H=0;
	H=1.75;

	if (N>=2) H+=5;
	if (N>=3) H+=5;
	if (N>=4) H+=(N-3)*3;

	ans=sqrt(2*H/9.8);
	printf("%.3lf\n",ans);
}

int main()
{
	while (cin>>N) 
	{
		if (N==0) break;
		deal();
	}

	return 0;
}


