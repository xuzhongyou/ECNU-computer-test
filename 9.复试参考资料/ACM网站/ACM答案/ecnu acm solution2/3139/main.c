#include <stdio.h>
#include <stdlib.h>

int calc(int n,int m);

int main(int argc, char *argv[]) 
{
	int a,m,n;
	scanf("%d",&a);
	while(a--){
		scanf("%d %d",&n,&m);
		if(calc(n,m)){
			printf("No answer\n");
		}
	}
	
	system("pause");	
	return 0;
}

int calc(int n,int m){
	int a;
	int b;
	if(m < 2*n  ||  m>4*n){
		return 1;
	}
	if((m-2*n)%2  == 1){
		return 1;
	}
	else{
		a =(m-2*n)/2;
		printf("%d %d\n",n-a,a);
		return 0;
	}
}
