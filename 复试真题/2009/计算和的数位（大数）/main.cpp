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
            char stra[100],strb[100];
            int ans[100],cnt=0,c=0;
            scanf("%s%s",stra,strb);
            int lenA=strlen(stra),lenB=strlen(strb);
            for(int i=lenA-1,j=lenB-1;i>=0&&j>=0;i--,j--)
            {
                ans[cnt]=stra[i]-'0'+strb[j]-'0'+c;
                if(ans[cnt]>9)
                {
                    ans[cnt]%=10;
                    c=1;
                }
                else c=0;
                cnt++;
            }
            if(lenA>lenB)
            {
                int i=lenA-lenB-1;
                while(i>=0)
                {
                    ans[cnt]=stra[i]+c-'0';
                    if(ans[cnt]>9)
                    {
                        ans[cnt]%=10;
                        c=1;
                    }
                    else c=0;
                    cnt++;
                    i--;
                }
                if(c>0)
                {
                    ans[cnt++]=1;
                }
            }
            else if(lenA<lenB)
            {
                int i=lenB-lenA-1;
                while(i>=0)
                {
                    ans[cnt]=strb[i]+c-'0';
                    if(ans[cnt]>9)
                    {
                        ans[cnt]%=10;
                        c=1;
                    }
                    else c=0;
                    cnt++;
                    i--;
                }
                if(c>0)
                    ans[cnt++]=1;
            }
            else{
                if(c>0)
                {
                    ans[cnt++]=1;
                }


            }
            //for(int i=cnt-1;i>=0;i--)
              //  printf("%d",ans[i]);
            //printf("\n");
            printf("%d\n",cnt);
        }

    }
}
