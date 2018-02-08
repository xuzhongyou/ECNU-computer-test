#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int hash[1001];
bool cmp(int a,int b)
{
    int x=a%10,y=b%10;
    return x<y;
}
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        int num;
        for(int i=0;i<T;i++)
        {
            int a[1001],cnt=0;
            for(int z=0;z<1001;z++)
                hash[z]=0;
            scanf("%d",&num);
            while(num--)
            {
                int x;
                scanf("%d",&x);
                hash[x]++;
            }
            printf("Case #%d\n",i);
            for(int j=0;j<1001;j++)
            {
                if(hash[j]!=0)
                    a[cnt++]=j;
            }
            sort(a,a+cnt,cmp);
            for(int k=0;k<cnt-1;k++)
                printf("%d ",a[k]);
            printf("%d\n",a[cnt-1]);
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
