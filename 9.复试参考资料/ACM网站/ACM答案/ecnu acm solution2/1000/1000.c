#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a;
	int b;
    while(scanf("%d%d",&a,&b)!=EOF)
        printf("%d\n",a+b);
	return 0;
}
