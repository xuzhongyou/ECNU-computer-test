#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int tower[5050];
	int c;
	int n;
	int count =0;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		while(n--){
			int i =n;
			while(i--){
				scanf("%d",&tower[count]);
				count++;
			}
		}
		path(tower);
	}
	system("pause");
	return 0;
}
