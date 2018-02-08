#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int num[1000010];
int pos[105];
int main()
{
    int n,i,k;
    while(scanf("%d"&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        scanf("%d",&k);
        for(i=1;i<=k;i++)
            scanf("%d",&pos[i]);
        sort(num+1,num+1+n);
        for(i=1;i<=k;i++)
            printf("%d\n",num[pos[i]);
    }
    return 0;
}
