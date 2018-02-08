#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10001];
int data[100];
int main()
{
    int T;
    int num;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&num);
            getchar();
            gets(s);
            int len=strlen(s);
            int sentence=0;
            int index=0;
            int jiludian=0;
            int flag=0;
            int i=0;
            int yaoqiu2=0;
            while(index<len)
            {
                if(jiludian>num)
                    flag=1;
                if(s[index]=='.'||s[index]=='?'||s[index]=='!')
                {
                    sentence++;
                    index+=2;
                    jiludian++;
                    if(jiludian>num)
                        flag=1;
                    data[i++]=jiludian;
                    jiludian=0;
                }
                else {index++;jiludian++;}
            }
            if(!flag)
               {
                   for(i=0;i<sentence-1;i++)
                    {
                        if((data[i]+data[i+1]+1)<=num)
                           {
                               yaoqiu2++;i++;
                           }

                    }
                    printf("%d\n",(sentence-yaoqiu2));
               }
            else printf("impossible\n");



        }
    }
    return 0;
}
