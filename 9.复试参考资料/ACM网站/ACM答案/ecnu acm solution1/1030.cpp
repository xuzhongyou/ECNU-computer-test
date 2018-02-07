#include <iostream>
using namespace std;

int N;
int F[100];

void init()
{
	int i,j,k;
	F[1]=1;
	F[2]=2;
	F[3]=3;

	for (i=4;i<=55;++i)
		F[i]=F[i-1]+F[i-3];

}


int main()
{
	init();

	while (cin>>N)
	{
		if (N==0) break;
		cout<<F[N]<<endl;
	}

	return 0;
}
