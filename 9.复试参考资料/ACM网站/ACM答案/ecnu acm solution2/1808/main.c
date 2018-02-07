#include <stdio.h>
#include <stdlib.h>

void
sort(int *array, int n);
int main(int argc, char *argv[]) 
{
	int array[1024];
	int n,j;
	int i = 0;
	scanf("%d",&n);
	for(j = 0;j<n;j++){
		scanf("%d",&array[i++]);
	}
	sort(array,n);
	for(j = 0; j<n; j++){
		if(j == n-1){
			printf("%d",array[j]);
		}else
			printf("%d ",array[j]);
	}
//	system("pause");
	return 0;
}

void
sort(int *array,int n){
	int i,j,temp;
	for(i = 0;i<n;i++){
		for(j = i;j<n;j++){
			if(array[i] > array[j]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}
