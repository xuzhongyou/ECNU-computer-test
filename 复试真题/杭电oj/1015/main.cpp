#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int is[15]={0};
int pow(int x,int y)
{
    int a=1;
    for(int i=0;i<y;i++)
       a=a*x;
    return a;
}
int fun(char v,char w,char x,char y,char z)
{
    return (pow((v-'A'+1),1)-pow((w-'A'+1),2)+pow((x-'A'+1),3)-pow((y-'A'+1),4)+pow((z-'A'+1),5));
}


bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    int tar;
    char a[15];
    while(scanf("%d%s",&tar,a)!=EOF&&(tar!=0)&&strcmp(a,"END"))
    {
        int len=strlen(a);
        sort(a,a+len,cmp);
        int flag=0;
        for(int v=0;v<len;v++)
        {
            if(flag==1)
                break;
            if(is[v]) continue;
            is[v]=1;
            for(int w=0;w<len;w++)
            {
                if(flag==1)
                            break;
                if(is[w])continue;
                is[w]=1;
                for(int x=0;x<len;x++)
                {
                    if(flag==1)
                            break;
                    if(is[x]) continue;
                    is[x]=1;
                    for(int y=0;y<len;y++)
                    {
                        if(flag==1)
                            break;
                        if(is[y]) continue;
                        is[y]=1;

                        for(int z=0;z<len;z++)
                        {
                            if(flag==1)
                            break;
                            if(is[z]) continue;
                            if(fun(a[v],a[w],a[x],a[y],a[z])==tar)
                           {
                                printf("%c%c%c%c%c\n",a[v],a[w],a[x],a[y],a[z]);
                                flag=1;
                                break;
                           }

                        }
                        is[y]=0;
                    }
                    is[x]=0;
                }
                is[w]=0;
            }
            is[v]=0;
        }
        if(flag==0)
            printf("no solution\n");
    }
    return 0;
}
