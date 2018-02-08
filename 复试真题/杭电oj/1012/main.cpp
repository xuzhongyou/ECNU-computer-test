#include <iostream>
#include <stdio.h>
using namespace std;
double e[10];
void f()
{
    int i=1;
    long double ii=1.0;
    e[0]=1;
    for(;i<=9;)
    {
        e[i]=e[i-1]+1/ii;
        i++;
        ii=ii*i;
    }
}
int main()
{

    int n;
    printf("n e\n");
    printf("- -----------\n");
    f();
    for(n=0;n<=9;n++)
    {
        if(n==0||n==1)
            printf("%d %.0f\n",n,e[n]);
        else if(n==2) printf("%d %.1f\n",n,e[n]);
        else printf("%d %.9f\n",n,e[n]);
    }
    return 0;
}
