#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int T;
    scanf("%d",&T);
    /*T loop*/
	float number;
	char string[100];
	float table[26];
    while(T--){
		int i = 0;
		while(scanf("%f",&number)!= '\n'){
			table[i] = number;
		}
		scanf("%s",string);


    }
	system("pause");	
	return 0;
}
