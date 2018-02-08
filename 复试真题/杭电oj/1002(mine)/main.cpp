#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[1000],b[1000];
int end1[1000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int k=1;k<=n;)
        {

            scanf("%s %s",a,b);
            int i=0,j=0,wei=0;
            int alen=strlen(a),blen=strlen(b);
            printf("Case %d:\n",k);
            printf("%s + %s = ",a,b);
            int ans=0;int allCount=0;
            i=alen-1,j=blen-1;
            while(i>=0&&j>=0)
            {
                ans=a[i]+b[j]-'0'-'0'+allCount;
                if(ans>9)
                    allCount=1;
                else allCount=0;
                end1[wei]=ans%10;
                wei++;
                i--;j--;
            }
            if(i>=0)
            {
                while(i>=0)
                {
                    ans=a[i]-'0'+allCount;
                    if(ans>9)
                        allCount=1;
                    else allCount=0;
                    end1[wei]=ans%10;
                    i--;
                    wei++;
                }
                if(allCount>0)
                    end1[wei]=allCount;
                else wei--;
                for(;wei>=0;wei--)
                   printf("%d",end1[wei]);


            }
            else if(j>=0)
            {
                while(j>=0)
                {
                    ans=b[j]-'0'+allCount;
                    if(ans>9)
                        allCount=1;
                    else allCount=0;
                    end1[wei]=ans%10;
                    j--;
                    wei++;
                }
                if(allCount>0)
                    end1[wei]=allCount;
                else wei--;
                for(;wei>=0;wei--)
                   printf("%d",end1[wei]);


            }
            else {
                if(allCount>0)
                    end1[wei]=allCount;
                else wei--;
                for(;wei>=0;wei--)
                   printf("%d",end1[wei]);

            }
            k++;
            if(k!=n+1)
                printf("\n\n");
            else
                 printf("\n");

        }



    }
    return 0;
}
