#include <iostream>
using namespace std;

long long ABC(int a,int b,int c)
{
	if (b==0) return 1;
	long long k;
	k=ABC(a,b/2,c);
	if (b % 2==0)
		return (k*k)%c;
	else
		return (((k*k) %c)*a)%c;
}

int N;

void judge()
{
	int i,j;
	bool ok=true;

	if (N==1) {printf("NO\n");return;}
	for (i=2;i<=3;++i)
	{
		j=ABC(i,N,N);
		if (j!=(i%N)) {ok=false;break;}
	}
	if (ok) printf("YES\n"); else printf("NO\n");
}

int main()
{
	while (scanf("%d",&N)==1) judge();
	return 0;
}
