#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    while(scanf("%d",&num)!=EOF&&num!=0)
    {
        int i;
        int Hash[101]={0};
        for(i=1;i<=num;i++)
        {
            int x;
            scanf("%d",&x);
            Hash[x]++;
        }
        int y;
        scanf("%d",&y);
        printf("%d\n",Hash[y]);
    }
    return 0;
}
