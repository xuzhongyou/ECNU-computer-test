#include <stdio.h>
#include <stdlib.h>
char a[100];
int index;
int A();
int B();
int C();

int A()
{
    while(a[index]==' ')
        index++;
    if(a[index]=='x')
    {
        index++;
        while(a[index]==' ')
            index++;
        return 1;
    }
    if(a[index]=='(')
    {
        index++;
        while(a[index]==' ')
            index++;

        if(B()&&a[index]==')')
        {
                index++;
            while(a[index]==' ')
                index++;
            return 1;

        }
    }
    return 0;
}
int B()
{
    return A()&&C();
}
int C()
{
    if(a[index]=='+')
    {
        index++;
        while(a[index]==' ')
            index++;
        if (!A())
            return 0;

    }
    return 1;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            index=0;
            gets(a);
            if(A())
                printf("GOOD!\n");
            else printf("BAD\n");
        }


    }
    return 0;
}
