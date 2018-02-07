#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main(int argc, char *argv[]) 
{
		int count = 0;
		char string[1025];
		while(gets(string)){
			count = strlen(string);
			printf("%d\n",count);
		}
	system("pause");
	return 0;
}
