#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct E{
    double pi;
    int di;
    bool operator > (const E &a) const
    {
        return di>a.di;
    }
}list[501];

bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int Cmax,Dis,Num,Davg;
    while(scanf("%d%d%d%d",&Cmax,&Dis,&Davg,&Num)!=EOF)
    {
        for(int i=0;i<Num;i++)
        {
            scanf("%lf%d",&list[i].pi,&list[i].di);
        }
        sort(list,list+Num,cmp);

    }
    cout << "Hello world!" << endl;
    return 0;
}
