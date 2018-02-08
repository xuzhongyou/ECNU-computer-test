#include <iostream>

#include <stdio.h>
using namespace std;

int main()
{
    int b;
	while(scanf("%d",&b)!=EOF)
    {
	    int a,ans,temp;
		int hash[11]={0};
		hash[b]++;
		for(int i=1;i<20;i++)
		{
		   scanf("%d",&a);
		   hash[a]++;
        }
        temp=0;
        for(int i=1;i<11;i++)
        {
            if(hash[i]>temp)
            {
                temp=hash[i];
                ans=i;
            }
        }
        printf("%d\n",ans);
	}
   return 0;
}
