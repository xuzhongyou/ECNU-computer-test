#include <stdio.h>
#include <stdlib.h>

void
convert(char *str);
int main(int argc, char *argv[])
{
	int N;
	scanf("%d",&N);
	char str[100];
	while(N--){
  		scanf("%s",&str);
  		convert(str);
	}
	system("pause");
	return 0;
}

void
convert(char *str){
	if(!strcmp("E",str)){
		printf("Excellent\n");
	}
	if(!strcmp("C",str)){
		printf("Cheer\n");
	}
	if(!strcmp("N",str)){
		printf("Nice\n");
	}if(!strcmp("U",str)){
		printf("Ultimate\n");
	}if(!strcmp("Impossible",str)){
		printf("I'm possible\n");
	}if(!strcmp("ACM",str)){
		printf("Accept More\n");
	}
}
