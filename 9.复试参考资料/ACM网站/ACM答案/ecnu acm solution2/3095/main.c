#include <stdio.h>
#include <stdlib.h>
void matrix_multiply(int *m1,int *m2,int *r, int x,int y,int z);
int main(int argc, char *argv[])
{
	int n,count;
	scanf("%d",&n);
	int matrix_1[100];
	int matrix_2[100];
	int result[100];
	int *r = result;
	for(count = 0;count <n*n ;count++){
		scanf("%d",&matrix_1[count]);
	}
	for(count = 0;count<n*n;count++){
		scanf("%d",&matrix_2[count]);
	}
	matrix_multiply(matrix_1,matrix_2,result,n,n,n);

	for(count = 0;count<n*n;count++,r++){
		printf("%d%c",*r,(count+1)%n !=0 ? ' ':'\n');
	}

	system("pause");
	return 0;
}
void matrix_multiply(int *m1,int *m2,int *r, int x,int y,int z){
	//return x row z column r
	//recive x row y column m1
	//recive y row z column m2
	int row,column,count;

	for(row = 0;row<x;row++){
		for(column = 0;column<z;column++){
			*r = 0;// ¡ï ¶Ôr³õÊ¼»¯¡£
			for(count = 0;count < y;count++){
				*r += *(m1 + row*y + count) * *(m2 + count*z +column);
			}
			r++;
		}
	}
}
