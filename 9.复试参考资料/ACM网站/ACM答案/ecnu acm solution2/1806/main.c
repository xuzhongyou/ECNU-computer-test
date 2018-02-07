#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647
void
selection_sort(int *array,int number);
int main(int argc, char *argv[])
{
	int array[1024];
    int n,i;
    scanf("%d",&n);
	for(i = 0;i<n;i++){
  		scanf("%d",&array[i]);
	}  // i最终为元素数量。
	selection_sort(&array[0],n);
	for(i = 0;i<n;i++){
		printf("%d%s",array[i],(i+1 == n)?"":" ");
	}
	system("pause");
	return 0;
}
void
selection_sort(int *array,int number){
	int i,j,low;
	int temp;
	int loc;
	for(i = 0;i<number;i++){
        //	printf("-");
		low = MAX;
		for(j = i;j<number;j++){
			//printf("--%d\n",array[low]);
			if(array[j]<=low){
				low = array[j];
				loc = j;
			}
		}
		temp = array[i];
		array[i] = array[loc];
		array[loc] = temp;
	}
	

}
