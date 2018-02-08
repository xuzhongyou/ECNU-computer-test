#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){

        if(n!=0)
        {
            int count[1000];
            memset(count,0,sizeof(count));
            int max=0;
            int c=0;
            char color[1000][15];
            for(int i=0;i<n;i++)
            {
                scanf("%s",color[i]);
                int j=0;
                while(j<i)
                {
                    if(strcmp(color[j],color[i])==0)
                    {
                        count[j]++;
                        if(count[j]>=max)
                        {
                            max=count[j];
                            c=j;
                        }
                        break;
                    }
                    j++;
                }
            }
            printf("%s\n",color[c]);
        }
        else break;
    }

    return 0;
}
