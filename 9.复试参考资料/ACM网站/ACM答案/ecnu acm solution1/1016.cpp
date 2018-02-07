#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("1016.in");

int N,F;
const double eps=1e-12;

int dcmp(double x)
{ return x<-eps ? -1 : x>eps; }

struct Point
{
	long long int x,y;
	Point(){}
	Point(long long int nx,long long int ny) {x=nx;y=ny;}
};

inline Point operator-(const Point &a,const Point &b)
{ return Point(a.x-b.x,a.y-b.y); }

inline long long int det(const Point &a,const Point &b)
{ return a.x*b.y-a.y*b.x; }

inline long long int det(const Point &p,const Point &a,const Point &b)
{ return det(a-p,b-p); }

Point p[100005];
Point np[100005];
int Ns;

void init()
{
	//cout<<"---------------------------"<<endl;

	p[0].y=0;
	p[0].x=0;
	
	long long int i,j,k;
	for (i=1;i<=N;++i)
	{
		fin>>j;
		//if (j==2000) cout<<j<<" "<<i<<endl;
		p[i].y=p[i-1].y+j;
		p[i].x=i;
	}

	//for (i=1;i<=N;++i) cout<<p[i].y<<" ";
	//cout<<endl;

	long double ans=0;
	int head=0;
	long double ans1,ans2;

	Ns=1;
	np[0].x=p[0].x;
	np[0].y=p[0].y;
	for (i=1;i<=N;++i)
	{
		//if (i==139) cout<<"np"<<np[Ns-2].x<<" "<<np[Ns-1].x<<endl;
		while (Ns>=2 && det(np[Ns-2],np[Ns-1],p[i])<0) {Ns--; if (Ns<head) head=Ns;}
		np[Ns].x=p[i].x;
		np[Ns].y=p[i].y;
		//if (i==139) cout<<"np"<<np[Ns-2].x<<" "<<np[Ns-1].x<<endl;
		Ns++;

		ans2=0;
			
		while (true)
		{
			if (head<=Ns-1 && p[i].x-np[head].x>=F)
			{
				ans1=(long double)1000*(long double)(p[i].y-np[head].y)/(long double)(p[i].x-np[head].x);
				if (dcmp(ans1-ans2)>0) {head++;ans2=ans1;}
			}
			else break;	
		}

		if (ans2>ans) ans=ans2;
	}

	cout<<(int)ans<<endl;
}

int main()
{
	while (	fin>>N>>F )init();

	system("pause");
	return 0;
}


