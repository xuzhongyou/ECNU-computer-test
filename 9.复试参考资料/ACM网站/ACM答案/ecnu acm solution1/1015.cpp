#include <iostream>
using namespace std;

long long int f[100][6];
bool used[100][6];

long long int cal(int N,int max)
{
	if (used[N][max]) return f[N][max];

	if (N==0) return 1;
	if (N==-1) return 1;
	if (N<0) return 0;
	if (N<max) return (1<<N);

	long long int ans=2*cal(N-1,max)-cal(N-max-1,max);

	f[N][max]=ans;
	used[N][max]=true;
	return ans;
}

int main()
{
	memset(used,false,sizeof(used));

	int i,j;
	while (cin>>i>>j)
	{
		cout<<cal(i,j)<<endl;
	}

	return 0;
}


