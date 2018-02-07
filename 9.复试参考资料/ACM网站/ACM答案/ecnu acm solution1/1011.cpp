#include <iostream>
using namespace std;

int Z,I,M,L;

int NL(int x)
{ return (Z*x+I) % M; }

void init()
{
	int walk,run;

	walk=NL(L);
	run=NL(walk);

	while (walk!=run)
	{
		walk=NL(walk);
		run=NL(NL(run));
	}

	int ans=1;
	int nwalk=NL(walk);
	while (nwalk!=walk)
	{
		ans++;
		nwalk=NL(nwalk);
	}
	cout<<ans<<endl;
}

int main()
{
	int cases=0;
	while (scanf("%d%d%d%d",&Z,&I,&M,&L)==4) 
	{
		if (Z==0 && I==0 && M==0 && L==0) break;
		cases++;
		printf("Case %d: ",cases);
		init();
	}
	return 0;
}