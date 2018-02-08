#include <iostream>

using namespace std;
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
bool check(int *a,int num,int len)
{
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]==0&&a[i+1]==1)
        {
            cnt++;
        }
    }
    if(cnt>=num)
        return true;
    else return false;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int Tol=0;
        for(int i=m;i<=n-m;i++)
        {
            int a[100]={0};
            for(int j=1;j<=i;j++)
            {
                a[n-j]=1;
            }
            do{
                if(check(a,m,n))
                {
                        Tol++;
                }

            }while(next_permutation(a,a+n));
        }
        printf("%d\n",Tol);
    }
    return 0;
}
