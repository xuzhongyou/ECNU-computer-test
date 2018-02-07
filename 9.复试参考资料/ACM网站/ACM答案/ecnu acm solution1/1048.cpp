#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[10001];

bool com(const int & a,const int & b)
{
	if (a>b) return true;
	return false;
}

void deal()
{
	int i,j,k;
	cin>>N;

	for (i=0;i<N;++i) scanf("%d",&T[i]);
	sort(T,T+N,com);

	long long int ans=0;
	for (i=1;i<N;++i) ans+=i*T[i];
	cout<<ans<<endl;
}

int main()
{
	int n;
	int i;

	cin>>n;

	for (i=1;i<=n;++i) deal();

	//system("pause");
	return 0;
}




