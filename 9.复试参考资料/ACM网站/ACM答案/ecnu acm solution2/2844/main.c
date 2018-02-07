#include <stdio.h>
#include <stdlib.h>


void a();

void d();
int main(int argc, char *argv[]) 
{
	char flag;
	int ch;
	scanf("%c",&flag);
	while((ch = getchar()) != EOF && ch !='\n')
	    ;
	    
	if(flag == 'A'){  ////ÉýÐò
        a();
	}
	
	
	if(flag == 'D'){    ////½µÐò
		d();
	}
	system("pause");	
	return 0;
}



void a(){
	int array[1001];
	memset(array,0,sizeof(int)*1001);

	int i = 0;
	int temp;
	int count = 0;
	for(i = 0;i<100;i++){
		scanf("%d",&temp);
		if(array[temp] == 0){
            count++;
		}
		array[temp] = 1;
		if(getchar() == '\n')
			break;
	}

	for(i =1;i<=1000;i++){

		if(array[i] ==1){
			printf("%d",i);
			if(--count > 0){
				printf(" ");
			}
		}

	}
}

void d(){
	int array[1001];
	memset(array,0,sizeof(int)*1001);
	int i = 0;
	int temp;
	int count = 0;
	for(i = 0;i<100;i++){
		scanf("%d",&temp);
		if(array[temp] == 0){
            count++;
		}
		array[temp] = 1;
		if(getchar() == '\n')
			break;
	}

	for(i =1000;i>=0;i--){

		if(array[i] ==1){
			printf("%d",i);
			if(--count > 0){
				printf(" ");
			}
		}

	}
}
