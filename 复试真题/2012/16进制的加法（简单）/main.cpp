#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long a,b;//或者long long a,b;
    while(scanf("%llx%llx",&a,&b)!=EOF)
    {
    printf("%llx\n",a+b);//%llx输出小写;%llX输出大写
    }
   // cout << "Hello world!" << endl;
    return 0;
}
