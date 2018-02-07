#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int n,a,b;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		printf("%d %d\n",GCD(a,b),a*b/GCD(a,b));
	}
	system("pause");	
	return 0;
}
void
change(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int
GCD(int a,int b){
    int x;
    while(b)
   {
		if(a<b){
        	change(&a, &b); //
		}
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}

int
LCM(int a,int b){
    
}
