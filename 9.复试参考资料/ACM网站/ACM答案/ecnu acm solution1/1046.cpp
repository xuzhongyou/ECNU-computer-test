#include <iostream>
#include <map>

using namespace std;


int num[5][5000];
int N;
long long int ans;
long long int plus;

map<int,int> times;
map<int,int>::iterator itr;

void search(int dep,int now)
{
	if (dep==4)
	{
		itr=times.find(-now);
		if (itr!=times.end()) ans+=itr->second;
		return;
	}

	for (int i=1;i<=N;++i)
		search(dep+1,now+num[dep][i]);
}

void init()
{
	int i,j;

	for (j=1;j<=N;++j)
		for (i=1;i<=4;++i)
			scanf("%d",&num[i][j]);

	/*
	for (j=1;j<=N;++j)
	{
		for (i=1;i<=4;++i) cout<<num[i][j]<<" ";
		cout<<endl;
	}
	*/

	times.clear();

	for (j=1;j<=N;++j)
	{
		if (times.find(num[4][j])==times.end())
			times[num[4][j]]=1;
		else
			times.find(num[4][j])->second++;
	}

	ans=0;
	search(1,0);

	cout<<ans<<endl;
}

int main()
{
	while (cin>>N)
	{
		init();
	}

	return 0;
}







	