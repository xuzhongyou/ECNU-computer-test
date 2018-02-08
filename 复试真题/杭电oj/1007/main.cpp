#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct m{
double x;
double y;
}a[100001];
double juli(int i,int j)
{
    double ans=sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
    return ans;
}
bool cmp1(const m a,m b)
{
    if(a.x<b.x)
        return true;
    if(a.x>b.x)
        return false;
    else return a.y<b.y;
}
bool cmp2(const m a,m b)
{
    if(a.y<b.y)
		return true;
	if(a.y>b.y)
		return false;
	else
		return a.x<b.x;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {

        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmp1);
        double radius=juli(0,1);
        for(int i=1;i<n-1;i++)
        {
            if(radius>juli(i,i+1))
                radius=juli(i,i+1);
        }
        sort(a,a+n,cmp2);
        for(int i=1;i<n-1;i++)
        {
            if(radius>juli(i,i+1))
                radius=juli(i,i+1);
        }
        printf("%.2lf\n",radius/2);
    }
    return 0;
}
