#include <iostream>
using namespace std;

const int MaxN=10;
const int MaxValue=20;
const int MaxUse=20;

int N;
int stamps;
int value[MaxN];
int times[MaxN];
bool F[10000];

int cases;
int ans;

void deal()
{
	int i,j,k;

	cin>>stamps;
	for (i=0;i<stamps;++i) cin>>value[i];
	for (i=0;i<stamps;++i) cin>>times[i];

	ans=0;
	memset(F,false,sizeof(F));
	F[0]=true;

	for (k=0;k<stamps;++k)
		for (i=4000;i>=0;i--)
			for (j=1;j<=times[k];++j)
			{
				if (i-value[k]*j>=0)
					if (F[i-value[k]*j]) F[i]=true;
			}

	for (i=0;i<=4000;++i) if (F[i]) ans++;

	cout<<ans<<endl;
}

int main()
{
	int i;

	while (cin>>cases)
	{
	for (i=1;i<=cases;++i)
		deal();
	}
	//system("pause");
	return 0;
}

