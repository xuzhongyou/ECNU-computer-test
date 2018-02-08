#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
char ex[110];
int index;
int A();
int B();
int C();
int A()
{
    if(ex[index]=='x')
    {
        index++;
        while(ex[index]==' ') index++;
        return true;
    }
    if(ex[index]=='(')
    {
        index++;
        while(ex[index]==' ') index++;
        if(B()&&ex[index]==')')
        {
            index++;
            while(ex[index]==' ') index++;
            return true;
        }
    }
    return false;
}
int B()
{
    return A()&&C();
}
int C()
{
    while(ex[index]=='+')
    {
        index++;
        while(ex[index]==' ') index++;
        return A();
    }
    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    while(N--)
    {
        gets(ex);
        index=0;
        printf("%s\n",A()&&ex[index]=='\0'?"Good":"Bad");
    }
    return 0;
}
