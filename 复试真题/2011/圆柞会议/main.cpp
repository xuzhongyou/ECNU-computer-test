#include <iostream>
#include <stdio.h>
using namespace std;
bool mark[100001];
int prime[100001];
int primeSize;
void init()
{
    primeSize=0;
    for(int i=2;i<=100000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        if(i>=1000)
            continue;
        for(int j=i*i;j<=100000;j+=i)
            mark[j]=true;
    }
}
int main()
{
    init();
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int n;
            scanf("%d",&n);
            int a[100000],flag=0;
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
            for(int i=1;i<=n/2;i++)
            {
                if(n%i==0)
                {
                    flag=1;
                    int cnt=1;
                    for(int j=0;j<i;j++)
                    {
                        int z=j+i;
                        do{
                            if(a[z]!=a[j])
                            {
                                flag=0;
                                //printf("%d",z);
                            }
                            cnt++;
                            z+=i;
                        }while(z<n);
                        if(flag&&cnt>=3)
                        {
                            puts("YES");
                            break;
                        }
                        else flag=0;

                    }
                    if(flag)
                        break;

                }
            }
            if(!flag)
                puts("NO");
        }
    }
   // cout << "Hello world!" << endl;
    return 0;
}
