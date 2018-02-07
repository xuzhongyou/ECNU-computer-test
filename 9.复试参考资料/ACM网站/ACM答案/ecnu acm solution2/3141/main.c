#include <stdio.h>
#include <stdlib.h>

int
add(int x,int y);
int main(int argc, char *argv[]) 
{
	int x,y;
	int result;
	while(scanf("%d %d",&x,&y) !=EOF){
		if(x ==0 && y==0){
			break;
		}
		printf("%d\n",add(x,y));
		
	}

	system("pause");
	return 0;
}
int
add(int x,int y){
	int result;
	result = x+y;
	int count = 0;
	while(x!=0){
		if((x%10 + y%10) >result%10 ){
			count++;
		}
		x /=10;
		y /=10;
		result /=10;
	}

	return count;
}

