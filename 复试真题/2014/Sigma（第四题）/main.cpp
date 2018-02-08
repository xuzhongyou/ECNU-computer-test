#include <iostream>
#include <stdio.h>
using namespace std;


int f(int n,int m)
{
    int a=0,b=1,c;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else {
        for(int i=2;i<=n;i++)
        {
            c=(a+b)%m;
            a=b%m;
            b=c;
            //printf("%d ",c);
        }
        return b;
    }
}
int main()
{
    long int n,m;
    while(scanf("%ld%ld",&n,&m)!=EOF)
    {
        printf("%d\n",f(2*n,m));
    }
    cout << "Hello world!" << endl;
    return 0;
}
