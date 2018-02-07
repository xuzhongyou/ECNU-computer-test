#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{

	int ch;
	int t;
	int character = 0;
	int number = 0;
	int others = 0;
	scanf("%d",&t);
	getchar();
	while(t--){
		character = 0;
		number = 0;
		others = 0;
		while((ch = getchar()) !=EOF && ch!='\n'){
			if(ch>='0' &&ch<='9')
				number++;
			else if((ch>='a' &&ch<='z') || (ch>='A' && ch<='Z'))
				character++;
			else
			    others++;
		}
		printf("character:%d\nnumber:%d\nothers:%d\n",character,number,others);
	}
	//system("pause");
	return 0;
}
