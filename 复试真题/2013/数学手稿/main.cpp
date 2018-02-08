#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        int cas=0;
        while(T--)
        {
            int num,money;
            scanf("%d%d",&num,&money);
            printf("Case #%d\n",cas++);
            for(int men=0;men<money/3+1;men++)
                for(int women=0;women<money/2+1;women++)
            {
                int child=num-men-women;
                if((men*3+women*2+child)==money)
                    printf("%d %d %d\n",men,women,child);
            }
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
