#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int N;// N组数据
	scanf("%d",&N);
	while(N--){
       	int x;//每组数据有x行
        scanf("%d",&x);
    	int matrix_one[100][100];
		int matrix_two[100][100];
		int matrix_result[100][100];
		int i,j,k;
		int result = 0;
		for(i = 0;i<x;i++){  // matrix_one
			for(j = 0;j<x;j++){
				scanf("%d",&matrix_one[i][j]);
			}
		}
		for(i = 0;i<x;i++){  // matrix_two
			for(j = 0;j<x;j++){
				scanf("%d",&matrix_two[i][j]);
				matrix_result[i][j] =0;
			}
		}
		for(i = 0;i<x;i++){  // matrix_result
			for(j = 0;j<x;j++){
				result = 0;
				for(k = 0;k<x;k++){
					result+=matrix_one[i][k]*matrix_two[k][j];
				}
				matrix_result[i][j] =result;
			}
		}
       	for(i = 0;i<x;i++){  // print result
			for(j = 0;j<x;j++){
				printf("%d%c",matrix_result[i][j],j==x-1?'\n':' ');

			}
		}
	}

	return 0;
}
