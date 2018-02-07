#include <iostream>
#include <cmath>
using namespace std;


int N;

void deal()
{
	int F[11];
	F[1]=1;
	F[2]=4;
	F[3]=2;
	F[4]=2;
	F[5]=3;
	F[6]=4;
	F[7]=8;
	F[8]=1;
	F[9]=3;
	F[10]=1;

	if (N<=10) 
	{
		cout<<F[N]<<endl;
		return ;
	}

	double ans=0;
	ans=log10((double)N)*(double)N;
	ans-=(int)ans;

	cout<<(int)pow(10,ans)<<endl;
}

int main()
{
	while (cin>>N)
	{
		if (N==0) return 0;
		deal();
	}

	return 0;
}



