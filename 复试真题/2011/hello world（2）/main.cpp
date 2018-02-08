#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int num;
            char str[10001];
            scanf("%d",&num);
            getchar();
            gets(str);
            int ans[500],len=strlen(str),cnt=0,now=0,cntEnd=0;
            for(int i=0;i<len;i++)
            {
                now++;
                if(str[i]=='.'||str[i]=='!'||str[i]=='?')
                {
                    ans[cnt++]=now;
                    now=0;
                    i++;
                }
            }
            cntEnd=cnt;
            //printf("%d",cnt);
            int flag=true;
            //for(int i=0;i<cnt;i++)
              //  printf("%d ",ans[i]);
            for(int i=0;i<cnt-1;i++)
            {
                if(ans[i]>num)
                    flag=false;
                if(ans[i]+ans[i+1]<num)
                {
                    ans[i+1]+=ans[i];
                    cntEnd--;
                }
            }
            if(ans[cnt-1]>num)
                flag=false;
            if(flag)
                printf("%d\n",cntEnd);
            else printf("Impossible\n");
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
