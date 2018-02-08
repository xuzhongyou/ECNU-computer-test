#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

#define eps 0.00000001
using namespace std;
struct E{
    int v;
    int pi;
    bool operator < (const E &A) const
    {
        return pi<A.pi;
    }
}list[101][101];

int main()
{
    int c;
    while(scanf("%d",&c)!=EOF)
    {
        for(int i=0;i<c;i++)//list[i][0] ·Å½âÒ©
        {
            int num,vc,YPi;
            scanf("%d%d%d",&num,&vc,&YPi);
            for(int j=1;j<=num;j++)
            {
                scanf("%d",&list[i][j].pi);
                list[i][j].v=vc;
            }
            sort(list[i]+1,list[i]+1+num);
            list[i][0].pi=0;
            list[i][0].v=0;
            int cnt=1;

            while(((list[i][0].pi+list[i][cnt].pi)<=(YPi*cnt))&&cnt<=num)
            {
                list[i][0].pi+=list[i][cnt].pi;
                list[i][0].v+=list[i][cnt].v;
                cnt++;
            }
            if(cnt==1)
                printf("0 0.00\n");
            else printf("%d %.2lf\n",list[i][0].v,((double)list[i][0].pi)/100/(cnt-1));

        }


    }
    return 0;
}
