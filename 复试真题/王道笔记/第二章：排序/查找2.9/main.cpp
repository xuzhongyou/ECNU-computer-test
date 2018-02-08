#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    int buf[201];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i=0,x,ans=-1;
        for(;i<n;i++)
        {
            scanf("%d",&buf[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
         if(x==buf[i])
         {
             ans=i;
             break;
         }
        }
        printf("%d",ans);
    }
    cout << "Hello world!" << endl;
    return 0;
}
