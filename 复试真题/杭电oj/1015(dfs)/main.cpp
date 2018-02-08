#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define N 15
using namespace std;
int a[5],len,tar,v[N];
char c[N];

int pow(int x,int y){
    int a=1,i;
    for(i=0;i<y;i++) a*=x;
    return y%2?a:-a;
}
int dfs(int cur,int cou)
{
    if(cou==5)
        return cur==tar;
    for(int i=len-1;i>=0;i--)
    {
        if(!v[i])
        {
            v[i]=1;
            int t=a[cou]=c[i]-'A'+1;
            if(dfs(cur+pow(t,cou+1),cou+1)) return 1;
            v[i]=0;
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d%s",&tar,c)!=EOF&&(tar||strcmp(c,"END")))
    {
        len=strlen(c);
        memset(v,0,sizeof(v));
        sort(c,c+len);
        if(dfs(0,0))
        {
            for(int i=0;i<5;i++)
                printf("%c",a[i]+'A'-1);
            printf("\n");
        }
        else printf("no solution\n");
    }
    return 0;
}
