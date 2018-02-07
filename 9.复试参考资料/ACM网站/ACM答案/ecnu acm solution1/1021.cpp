#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

const double R=4000;
const double INFINITE=1e10;

struct Posi
{
	string name;
	double phi;
	double the;
	double x,y,z;
};

int N,M;
double dis[200][200];
Posi p[200];

map<string,int> NametoID;
map<string,int>::iterator itr;
map<string,int>::iterator itr2;

double SQR(const Posi &a)
{ return sqrt( a.x*a.x+a.y*a.y+a.z*a.z); }

double dealdis(const Posi &a,const Posi &b)
{
	double ans=a.x*b.x+a.y*b.y+a.z*b.z;
	ans/=SQR(a);
	ans/=SQR(b);
	ans=acos(ans);
	return ans*R;
}

void init()
{
	cin>>N>>M;
	NametoID.clear();
	
	int i,j,k;
	char c1,c2;
	for (i=1;i<=N;++i)
	{
		cin>>p[i].name>>p[i].phi>>c1>>p[i].the>>c2;
		p[i].x=R*cos(p[i].phi)*sin(p[i].the);
		p[i].y=R*cos(p[i].phi)*cos(p[i].the);
		p[i].z=R*sin(p[i].phi);
		if (c1=='S') p[i].z=-p[i].z;
		if (c2=='W') p[i].x=-p[i].x;
		NametoID[p[i].name]=i;
	}

	for (i=1;i<=N;++i) for (j=1;j<=N;++j) dis[i][j]=INFINITE;
	string s1,s2;
	int t1,t2;
	for (i=1;i<=M;++i)
	{
		cin>>s1>>s2;
		itr=NametoID.find(s1);
		itr2=NametoID.find(s2);
		t1=itr->second;t2=itr2->second;
		dis[t1][t2]=dis[t2][t1]=dealdis(p[t1],p[t2]);
	}

	for (k=1;k<=N;++k)
		for (i=1;i<=N;++i)
			for (j=1;j<=N;++j)
				if (dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];

	double ans=0;
	t1=t2=0;

	for (i=1;i<=N;++i)
		for (j=1;j<=N;++j)
			if (dis[i][j]>ans && dis[i][j]!=INFINITE && i!=j)
			{
				ans=dis[i][j];t1=i;t2=j;
			}

	s1=p[t1].name;
	s2=p[t2].name;
	if (s1>s2) swap(s1,s2);
	cout<<s1<<" "<<s2<<endl;
}

int main()
{
	string s1="a";
	string s2="aab";
	cout<<(s1<s2)<<endl;

	int t;
	cin>>t;
	while (t--)
	{
		init();
	}

	return 0;
}


