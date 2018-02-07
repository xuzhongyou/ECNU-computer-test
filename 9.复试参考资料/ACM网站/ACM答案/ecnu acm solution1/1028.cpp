#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

ifstream fin("1.in");

int dis[200][200];
int N;
int M;

map<string,int> ID;

void init()
{
	int i,j,k;

	ID.clear();
	cin>>N>>M;
	for (i=1;i<=N;++i) 
		for (j=1;j<=N;++j) dis[i][j]=99999999;

	int curr=0;
	string s1,s2;
	int id1,id2;

	for (i=1;i<=M;++i)
	{
		cin>>s1>>s2>>k;
		if (ID.find(s1)==ID.end())
		{
			curr++;
			ID[s1]=curr;
		}
		if (ID.find(s2)==ID.end())
		{
			curr++;
			ID[s2]=curr;
		}
		id1=ID.find(s1)->second;
		id2=ID.find(s2)->second;

		if (k<dis[id1][id2])
		{
			dis[id1][id2]=k;
			dis[id2][id1]=k;
		}
	}


	for (k=1;k<=N;++k)
		for (i=1;i<=N;++i)
			for (j=1;j<=N;++j)
				if (dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];

	cin>>k;

	for (i=1;i<=k;++i)
	{
		cin>>s1>>s2;
		id1=-1;
		id2=-1;
		if (ID.find(s1)!=ID.end()) id1=ID.find(s1)->second;
		if (ID.find(s2)!=ID.end()) id2=ID.find(s2)->second;

		if (dis[id1][id2]==99999999 || id1==-1 || id2==-1) cout<<-1<<endl;
		else cout<<dis[id1][id2]<<endl;
	}

}


int main()
{
	while (!cin.eof()) init();

	//system("pause");
	return 0;
}
