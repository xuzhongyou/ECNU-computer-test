#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[301],b[301]={-1};
        int cnt=1;
        scanf("%d",&a[0]);
        b[0]=a[0];
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            int flag1=1,flag2=0,jian;
            for(int j=0;j<cnt;j++)
            {
                if(a[i]==b[j])
                    flag1=0;
                if((a[i]*2)==b[j])
                {
                    flag2=1;
                    jian=j;
                }

            }
            if(flag1&&flag2)
                b[jian]=-1;
            int flag3=0;
            for(int j=0;j<cnt;j++)
            {
                if(b[j]==a[i])
                    flag3=1;
            }
            if(flag3==0)
                b[cnt++]=a[i];

        }
        int cnt1=cnt;
        for(int k=0;k<cnt;k++)
        {
            if(b[k]==-1)
                cnt1--;

        }

       printf("%d\n",cnt1);
    }
    return 0;
}
