#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int ans,song5=0,song3=0;
            ans=a/b;
            if(ans>=5)
                song5+=(ans/5)*2;
            if(ans%5>=3)
                song3+=(ans%5)/3;
            printf("%d\n",ans+song3+song5);
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
