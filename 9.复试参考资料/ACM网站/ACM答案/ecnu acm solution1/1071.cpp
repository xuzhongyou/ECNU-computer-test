#include <iostream>
#include <string>
using namespace std;

bool ok[11];
char state[100];

void deal()
{
	int i,j,k;
	memset(ok,true,sizeof(ok));

	while (true)
	{
		cin>>k;
		if (k==0) break;
		cin.getline(state,20,'\n');
		cin.getline(state,20,'\n');

		if (strcmp(state,"right on")==0)
		{
			if (ok[k]) cout<<"Sunny may be honest"<<endl;
			else cout<<"Sunny is dishonest"<<endl;
			memset(ok,true,sizeof(ok));
		}

		if (strcmp(state,"too high")==0)
		{
			for (i=k;i<=10;++i) ok[i]=false;
		}

		if (strcmp(state,"too low")==0)
		{
			for (i=1;i<=k;++i) ok[i]=false;
		}
	}
}

int main()
{
	deal();

	return 0;
}

