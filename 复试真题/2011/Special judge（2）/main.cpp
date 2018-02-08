#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            double s,t,e;
            scanf("%lf%lf%lf",&s,&t,&e);
            if(fabs(s-t)<=e)
                puts("Accept");
            else puts("Wrong Answer");
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
