#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX 10001

char stack[MAX];
int top = 0;
int push(x)
int x;
{
	if(top>=MAX){
		return 0;  // stack full return 0 failed
	}
	stack[top++] = (char)x;
	return 1;
}
int pop()
{
	if(top == 0){
		return 0;// stack empty return '' failed
	}
	printf("%c",stack[--top]);  // return the data in stack top
}
void output(){
	while(pop() != 0);
}
int main(int argc, char *argv[]) 
{
	int len;
    char str[10001];
    while(gets(str)){
		len = strlen(str);
		while(len--){
		printf("%c",str[len]);
		}
		printf("\n");
	}
#if 0

	int ch;
	while(push((ch = getchar())),ch!=EOF){
		if(ch =='\n'){
			top--;
			output();
			printf("\n");
		}
	}
#endif
//	system("pause");
	return 0;
}
