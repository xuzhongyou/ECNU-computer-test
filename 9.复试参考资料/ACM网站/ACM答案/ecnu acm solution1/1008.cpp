#include <iostream>
using namespace std;

const int five[9]={5,25,125,625,5*5*5*5*5,5*5*5*5*5*5,5*5*5*5*5*5*5,5*5*5*5*5*5*5*5,5*5*5*5*5*5*5*5*5};


void init()
{
	int N;
	int ans;
	int i;

	while (cin>>N)
	{
		ans=0;
		for (i=0;i<9;++i) ans+=(N/five[i]);
		cout<<ans<<endl;
	}
}

int main()
{
	init();

	//system("pause");
	return 0;
}