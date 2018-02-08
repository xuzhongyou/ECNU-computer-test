#include <iostream>
#include <stdio.h>
#define N 200000
using namespace std;
int a[N+1];
int main()
{
    for(int i=0;i<N;i++)
        a[i]=0;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(a[i])
            continue;
        if(i>=2000) continue;
        for(int j=i*i;j<=N;j+=i)
            a[j]=1;
        //for(int j=2;i*j<N+1&&j<N;j++)
          //  a[j*i]=1;
    }
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int i=0,count=0;
        for(;i<N+1;i++)
        {
            if(a[i]!=1)
                count++;
            if(count==n)
            {
                printf("%d\n",i);
                break;
            }

        }
    }
    return 0;
}
