#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps=1e-8;

inline int dcmp(double x)
{ return x<-eps ? -1 : x>eps ;}

struct Point
{
	double x,y;
	Point(){}
	Point(double nx,double ny) {x=nx;y=ny;}
};

inline Point operator-(const Point &a,const Point &b)
{ return Point(a.x-b.x,a.y-b.y); }

inline bool com(const Point &a,const Point &b)
{ return dcmp(a.y-b.y)<0 || dcmp(a.y-b.y)==0 && dcmp(a.x-b.x)<0; }

inline double det(const Point &a,const Point &b)
{ return a.x*b.y-a.y*b.x ;}

inline double det(const Point &p,const Point &a,const Point &b)
{ return det(a-p,b-p); }

inline double Distant(const Point &a,const Point &b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

int N;
int Ns;
Point p[30001];
Point np[30001];

void Convex_Hull()
{
	int i,k;
	sort(p,p+N,com);

	Ns=0;
	for (i=0;i<N;++i)
	{
		while (Ns>=2 && dcmp(det(np[Ns-2],np[Ns-1],p[i]))<=0) Ns--;
		np[Ns++]=p[i];
	}

	k=Ns;
	for (i=N-2;i>=0;i--)
	{
		while (Ns>k && dcmp(det(np[Ns-2],np[Ns-1],p[i]))<=0) Ns--;
		np[Ns++]=p[i];
	}

	Ns--;
}


void init()
{
	int i;
	for (i=0;i<N;++i) scanf("%lf%lf",&p[i].x,&p[i].y);

	Convex_Hull();

	
	double ans=0;
	int j;
	double temp=0,temp2=0;

	for (i=j=0;i<Ns;++i)
	{
		for (temp=Distant(np[i],np[j]);;)
		{
			temp2=Distant(np[i],np[(j+1)%Ns]);
			if (dcmp(temp2-temp)>0)
			{
				temp=temp2;
				j=(j+1)%Ns;
			} 
			else break;
		}

		if (dcmp((temp-ans))>0) ans=temp;
	}

	printf("%.2lf\n",ans);
	
}


int main()
{

	while (scanf("%d",&N)==1) init();
	return 0;
}

