#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int e,f,c;
    while(scanf("%d%d%d",&e,&f,&c)!=EOF)
    {
        int ans=0;
        while(e+f>=c)
        {
            f+=e;
            ans+=f/c;
            e=f/c;
            f=f%c;

        }
        printf("%d\n",ans);
    }
    cout << "Hello world!" << endl;
    return 0;
}
