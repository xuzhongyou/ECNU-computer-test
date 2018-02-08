#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Student{
    char no[100];
    char name[100];
    int score;
}buff[100000];

bool cmp1(Student a,Student b)
{
   return atoi(a.no)<atoi(b.no);
}

bool cmp2(Student a,Student b)
{
    int tmp=strcmp(a.name,b.name);
    if(tmp==0)
        return atoi(a.no)<atoi(b.no);
    else return tmp<0;
}
bool cmp3(Student a,Student b)
{
    if(a.score==b.score)
        return atoi(a.no)<atoi(b.no);
    else return a.score<b.score;
}
int main()
{
    int n,c,cas=0;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        if(n==0&&c==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%s%s%d",buff[i].no,buff[i].name,&buff[i].score);
        }
        switch(c){
        case 1:sort(buff,buff+n,cmp1);break;
        case 2:sort(buff,buff+n,cmp2);break;
        case 3:sort(buff,buff+n,cmp3);break;
        default:break;
        }
        printf("Case %d:\n",++cas);
        for(int i=0;i<n;i++)
            printf("%s %s %d\n",buff[i].no,buff[i].name,buff[i].score);

    }
    return 0;
}
