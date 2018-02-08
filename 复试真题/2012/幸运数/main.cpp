#include <iostream>
#include  <stdio.h>

using namespace std;

bool mark[10001];
int prime[10000];
int primeSize;
void init()
{
    primeSize=0;
    int i;
    for(i=1;i<=10000;i++)
        mark[i]=false;
    for(int i=2;i<=10000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        for(int j=i*i;j<=10000;j++)
            mark[j]=true;
    }
}

bool judge(int x)
{
    while(x>0)
    {
        if(x%10==8)
            return true;
        x/=10;
    }
    return false;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        if(judge(n))
        {
            puts("YES");
            flag=1;
        }
        else{
            for(int i=0;i<primeSize&&prime[i]<=n;i++)
            {
                if(n%prime[i]==0)
                {
                    if(judge(prime[i]))
                    {
                        puts("YES");
                        flag=1;
                    }
                    else
                    {
                        n/=prime[i];
                        i--;
                    }
                }
                if(flag==1)
                    break;
            }
        }
        if(flag==0)
            puts("NO");
    }
    cout << "Hello world!" << endl;
    return 0;
}
