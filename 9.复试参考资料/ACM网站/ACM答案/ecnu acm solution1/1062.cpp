#include <iostream>
using namespace std;

struct Point
{
	long long int x,y;

	long long int operator*(const Point & b)
	{
		return x*b.y-y*b.x;
	}

	Point operator-(const Point & b)
	{
		Point temp;
		temp.x=x-b.x;
		temp.y=y-b.y;
		return temp;
	}
};

int sgn(long long int x)
{
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}

long long int Min(long long int a,long long int b)
{
	if (a<b) return a;
	return b;
}

long long int Max(long long int a,long long int b)
{
	if (a>b) return a;
	return b;
}

bool intersection(Point a,Point b,Point c,Point d)
{
	if (Max(a.x,b.x)<Min(c.x,d.x) || Max(a.y,b.y)<Min(c.y,d.y) 
		|| Max(c.x,d.x)<Min(a.x,b.x) || Max(c.y,d.y)<Min(a.y,b.y)) return false;

	int s1=sgn((b-a)*(c-a));
	int s2=sgn((b-a)*(d-a));
	int s3=sgn((d-c)*(a-c));
	int s4=sgn((d-c)*(b-c));

	if (s1*s2==1 || s3*s4==1) return false;
	return true;
}


int main()
{
	Point a,b,c,d;

	while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y)
	{
		if (intersection(a,b,c,d)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;

}


