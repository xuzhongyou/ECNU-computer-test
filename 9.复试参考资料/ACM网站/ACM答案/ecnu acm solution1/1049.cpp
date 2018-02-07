#include <iostream>
#include <map>
using namespace std;

int n,m;
map<int,int> ans;
map<int,int>::iterator itr;

void init()
{
	ans.clear();
	int i,k;
	for (i=1;i<=n;++i)
	{
		scanf("%d",&k);
		itr=ans.find(k);
		if (itr==ans.end())
			ans[k]=1;
		else 
			itr->second++;
	}

	for (i=1;i<=m;++i)
	{
		scanf("%d",&k);
		itr=ans.find(k);
		if (itr==ans.end())
			cout<<0<<endl;
		else 
			cout<<itr->second<<endl;
	}
}

int main()
{
	while (	scanf("%d%d",&n,&m)==2 ) init();

	return 0;
}


