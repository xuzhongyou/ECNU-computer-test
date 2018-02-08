#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
struct goods{
    double j;
    double f;
    double s;
    bool operator <(const goods &A) const{
        return s>A.s;
    }
}buf[1000];

int main()
{
    double m;
    int n;
    while (scanf("%lf%d",&m,&n)!=EOF)
    {
        if(m==-1&&n==-1)
            break;
        int i=0;
        for(;i<n;i++)
        {
            scanf("%lf%lf",&buf[i].j,&buf[i].f);
            buf[i].s=buf[i].j/buf[i].f;
        }
        sort(buf,buf+n);
        //for(i=0;i<n;i++)
           // printf("%lf %lf %lf\n",buf[i].j,buf[i].f,buf[i].s);
        int idx=0;
        double ans=0;
        while(m>0&&idx<n)
        {
            if(m>buf[idx].f)
            {
                m-=buf[idx].f;
                ans+=buf[idx].j;
            }
            else{

                ans+=buf[idx].s*m;m=0;
            }
            idx++;
        }
        printf("%.3lf\n",ans);


    }
    return 0;
}
