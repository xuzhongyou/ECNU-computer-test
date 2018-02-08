#include <stdio.h>
#include <stdlib.h>

struct abc
{
    int num;
    int test;
};
struct abc another,other;
int testV(int i)
{
    if(i==0||i==1)
        return 0;
    if(i==2)
        return 1;
    int k=2;
    for(;k<(i/2+1);k++)
        if(i%k==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    int sample[100];
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i=0;i<n;i++)
        {
            int numOf=0;
            scanf("%d",&sample[i]);
            printf("sample=%d\n",sample[i]);
            sample[i]++;
            for(other.num=1;other.num<sample[i];other.num++)
            {
                other.test= testV(other.num);
                another.num=sample[i]-other.num;
                another.test=testV(another.num);
                if(another.test&&other.test)
                {printf("%d %d\n",other.num,another.num);numOf++;}
            }
            printf("%d\n",numOf);
        }

    }
    return 0;
}
