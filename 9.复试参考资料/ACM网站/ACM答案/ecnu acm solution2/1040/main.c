#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int n;
	int i;
	int j;
	int array[21][21];
	int value[21];
	double result[21];
	scanf("%d",&n);

	for(i = 0;i<n;i++){
		for(j = 0;j <n;j++){
			scanf("%d",&array[i][j]);
		}
	}
	for(i = 0;i<n;i++){
		scanf("%d",&value[i]);
	}
	
	system("pause");	
	return 0;
}
void
convert_to_triangle(int **array,int n){
	int i;
	for(i = 0;i< n ;i++){
		*(*array) = *(*array) / *array[0];
		*(*array)++;
 	}
}
