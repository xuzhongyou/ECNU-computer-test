#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//ifstream fin("1.in");

int N;
string s;

void convert(string & x)
{
	int i,j,k;
	int ans;

	for (i=0;i<4;++i)
	{
		ans=0;
		for (j=i*8;j<(i+1)*8;++j)
		{
			if (x[j]=='1') ans=(ans<<1)+1;
			else ans=ans<<1;
		}
		if (i<3) cout<<ans<<".";
		else cout<<ans<<endl;
	}

}


void init()
{
	cin>>N;
	int i;

	for (i=1;i<=N;++i)
	{
		cin>>s;
		convert(s);
	}

}


int main()
{
	init();

	//system("pause");
	return 0;
}