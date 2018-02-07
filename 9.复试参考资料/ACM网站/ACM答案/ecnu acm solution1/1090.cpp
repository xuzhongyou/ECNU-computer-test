#include <iostream>
#include <cmath>
using namespace std;

const double eps=0.005;
const double PI2=acos(-1.0)/2;
const double PIPI=acos(-1.0)*2;

inline int dcmp(double x)
{ return x<-eps ? -1 : x>eps; }

inline double sqr(double x)
{ return x*x; }

struct Point
{
	double x,y;
	Point(){}
	Point(double nx,double ny) {x=nx;y=ny;}
};

inline Point operator-(const Point &a,const Point &b)
{ return Point(a.x-b.x,a.y-b.y); }

inline double Distant(const Point &a,const Point &b)
{ return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) ); }

inline double det(const Point &a,const Point &b)
{ return a.x*b.y-a.y*b.x; }

inline double det(const Point &p,const Point &a,const Point &b)
{ return det(a-p,b-p); }

inline double dot(const Point &a,const Point &b)
{ return a.x*b.x+a.y*b.y; }

inline double dot(const Point &p,const Point &a,const Point &b)
{ return dot(a-p,b-p); }

Point a,b,c;
double ab,bc,ca;
double ang1,ang2,ang3;

void init()
{
	if (dcmp (det(a,b,c))==0) {cout<<"Not a Triangle"<<endl; return;}
	ab=Distant(a,b);
	bc=Distant(b,c);
	ca=Distant(c,a);


	int ans1=0;
	if ( dcmp(ab-bc)==0 ) ans1++;
	if ( dcmp(ab-ca)==0 ) ans1++;
	if ( dcmp(bc-ca)==0 ) ans1++;

	if (ans1==0) cout<<"Scalene";
	if (ans1==1) cout<<"Isosceles";
	if (ans1==3) cout<<"Equilateral";

	ang1= dot(a,b,c)/ab/ca;
	ang1= acos(ang1);
	ang2= dot(b,a,c)/ab/bc;
	ang2= acos(ang2);
	ang3= dot(c,a,b)/ca/bc;
	ang3= acos(ang3);

	int ans2=0;
	if (dcmp(ang1-PI2)==0) ans2++;
	if (dcmp(ang2-PI2)==0) ans2++;
	if (dcmp(ang3-PI2)==0) ans2++;
	if (ans2>0) { cout<<" Right"<<endl; return ;}

	ans2=0;
	if (dcmp (ang1-PI2) >0) ans2++;
	if (dcmp (ang2-PI2) >0) ans2++;
	if (dcmp (ang3-PI2) >0) ans2++;
	if (ans2>0) {cout<<" Obtuse"<<endl; return;}

	cout<<" Acute"<<endl;
}

int main()
{
	while (scanf("%lf",&a.x)==1) 
	{
		if (scanf("%lf%lf%lf%lf%lf",&a.y,&b.x,&b.y,&c.x,&c.y)==EOF) 
		{
			cout<<"End of Output"<<endl;
			break;
		}
		init();
	}

	return 0;
}


