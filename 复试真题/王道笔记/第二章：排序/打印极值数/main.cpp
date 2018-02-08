#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int b[1000][80],count[1000],num=0;
        while(n--)
        {
            int a[80];
            int k,cnt=-1;
            scanf("%d",&k);
            for(int i=0;i<k;i++)
            {
                scanf("%d",&a[i]);
                if(i==1&&(a[i-1]<a[i]||a[i-1]>a[i]))
                {
                    b[num][++cnt]=0;
                }
                if(i>=2&&((a[i-1]>a[i]&&a[i-1]>a[i-2])||(a[i-1]<a[i]&&a[i-1]<a[i-2])))
                   b[num][++cnt]=i-1;
                if(i==k-1&&(a[i]<a[i-1]||a[i]>a[i-1]))
                    b[num][++cnt]=i;
            }
            count[num]=cnt;
            num++;

        }
        for(int j=0;j<num;j++)
        {
            for(int i=0;i<count[j];i++)
                printf("%d ",b[j][i]);
            printf("%d\n",b[j][count[j]]);
        }


    }
    return 0;
}
