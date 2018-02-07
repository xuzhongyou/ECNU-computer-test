#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	__int64 a,b;
	while(scanf("%I64d %I64d",&a,&b) != EOF){
		printf("%I64d\n",a+b);
	}
	system("pause");	
	return 0;
}
