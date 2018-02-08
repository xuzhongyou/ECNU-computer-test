#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double a=0;
    double n=1.0;
    double s=1.0;
    while(fabs(s)>=1e-6)
    {
        s/=n;
        a+=s;
        s=-s;
        n++;
        printf("%f\n",a);
    }
    return 0;
}
