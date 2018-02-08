#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    char x[1000];
    while(scanf("%s",x)!=EOF)
    {
        int len=strlen(x),ans;
        if(len==1&&x[0]=='0')
            break;
        if(len==1)
            ans=x[0]-'0';
        else
        {
            ans=0;
            for(int i=0;i<len;i++)
                ans+=x[i]-'0';
            int tmp=ans;
            while(tmp>9)
            {
                ans=0;
                while(tmp>=1)
                {
                    ans+=tmp%10;
                    tmp/=10;
                }
                tmp=ans;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
