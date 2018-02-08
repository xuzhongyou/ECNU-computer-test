#include <iostream>

using namespace std;
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        char a[501],b[501];
        int dp[501][501];
        scanf("%s%s",a,b);
        int len1=strlen(a),len2=strlen(b);
        for(int i=0;i<=len1;i++)
            dp[i][0]=0;
        for(int i=0;i<=len2;i++)
            dp[0][i]=0;
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
        {
            if(a[i-1]!=b[j-1])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=dp[i-1][j-1]+1;
        }
        printf("%d\n",max(len1,len2)-dp[len1][len2]);

    }
   // cout << "Hello world!" << endl;
    return 0;
}
