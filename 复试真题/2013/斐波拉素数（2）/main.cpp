#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int f(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    else return f(n-1)+f(n-2);
}
int prime[10000];
int primeSize;
bool mark[10001];
void init()
{
    for(int i=1;i<=10000;i++)
        mark[i]=false;
    primeSize=0;
    for(int i=2;i<=10000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        for(int j=i*i;j<=10000;j+=i)
            mark[j]=true;
    }
   // printf("%d\n",cnt);
}

int main()
{
    init();
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        a=f(a);
        b=f(b);
        int cnt=0;
       // printf("%d %d\n",a,b);
        for(int i=0;i<primeSize;i++)
        {
            if(prime[i]>=min(a,b)&&prime[i]<=max(a,b))
                cnt++;
            //printf("%d ",prime[i]);
        }
        printf("%d\n",cnt);
    }
    cout << "Hello world!" << endl;
    return 0;
}
