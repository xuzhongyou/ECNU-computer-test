#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int fun(int n,int a)
{
    int t1=log(n)/log(2)+1;
    int t2=log(a)/log(2)+1;
    int end =t1-t2;
    int sum=0,k=1;
    for(int i=0;i<end;i++)
    {
        sum+=k;
        k*=2;
    }
   // printf("%d %d",sum,k);
    int start=a*k,end1=start+k;
    if(start<=n)
    {
        if(end1<=n)
            sum+=k;
        else {
            sum+=n-start+1;
        }
    }

    return sum;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n==0||m==0)
            break;
        int cnt=fun(n,m);
        printf("%d\n",cnt);
    }
    return 0;
}
