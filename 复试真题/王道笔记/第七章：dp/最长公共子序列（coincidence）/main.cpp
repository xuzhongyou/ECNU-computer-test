#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[101][101];
int max(int a,int b) {return a>b?a:b;}

int main()
{
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=0;i<=len1;i++)
            dp[i][0]=0;
        for(int j=0;j<=len2;j++)
            dp[0][j]=0;
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]!=s2[j-1])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else dp[i][j]=dp[i-1][j-1]+1;
        }

        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
