#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char s[10000];
    while(scanf("%s",s)!=EOF&&s[0]!='0')
    {
        int len=strlen(s);
        int sum=0;
        for(int i=len-1;i>=0;i--)
        {
            sum+=s[i]-'0';
        }
        while(sum>9)
        {
            sum=sum%9;
        }
        if(sum==0)
            sum=9;
        printf("%d\n",sum);
    }
    return 0;
}
