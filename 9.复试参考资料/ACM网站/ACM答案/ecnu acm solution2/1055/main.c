#include <stdio.h>
#include <stdlib.h>
//这个倒是挺顺利！！
int main(int argc, char *argv[]) 
{
	unsigned int a,b;
	unsigned int result;
	while(scanf("%d %d",&a,&b)!=EOF){
		result = euclidean(a,b);
		printf("%d\n",result);
	}
	system("pause");	
	return 0;
}
int
euclidean(int a,int b){
	int temp;
	if(a>b){
		change(&a,&b);
	}// reuslt a<b;
	temp = b%a;
	if(temp == 0){
		return a;
	}
	euclidean(a,temp);
}

void change(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
