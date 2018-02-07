#include <stdio.h>
#include <stdlib.h>
#include "string.h"
void
prog();
void
test();
int main(int argc, char *argv[])
{
	test();
	return 0;
}
void
prog(){
    int ch;
	while((ch =getchar() ) != EOF){
		if((char)ch == ' ' || (char)ch == '.'){
			putchar((char)ch);
		}
		putchar(toupper((char)ch));
	}
}
void
test(){
    char ch;
	while((scanf("%c",&ch) ) != EOF){
		putchar(toupper(ch));
	}
}
