#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int dp[100][100];

int dy(char strA[],int lenA,char strB[],int lenB)
{
    for(int i=0;i<=lenA;i++)
        dp[i][0]=i;
    for(int j=0;j<=lenB;j++)
        dp[0][j]=j;
    //dp[0][0]=0;
    for(int i=1;i<=lenA;i++)
    {
        for(int j=1;j<=lenB;j++)
        {
            if(strA[i]==strB[j])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                if(strA[i-1]==strB[j]&&strA[i]==strB[j-1]&&i>1&&j>1)
                {
                    //puts("swap");
                    dp[i][j]=min(dp[i-2][j-2],min(dp[i-1][j-2],dp[i-2][j-1]))+1;//考虑到又可以替换又可以删除又可以插入所以要对其周围比较
                }
                else dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;

            }
            //printf(" %d ",dp[i][j]);
        }
       // printf("\n");
    }

    return dp[lenA][lenB];

}
int main()
{
    char strA[100],strB[100];
    while(scanf("%s%s",strA+1,strB+1)!=EOF)
    {
        int lenA=strlen(strA+1),lenb=strlen(strB+1);
        int cnt=dy(strA,lenA,strB,lenb);
        printf("%d\n",cnt);

    }
   // cout << "Hello world!" << endl;
    return 0;
}
