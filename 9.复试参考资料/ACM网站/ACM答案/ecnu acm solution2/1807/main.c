#include <stdio.h>
#include <stdlib.h>
//快速排序
#define min 3

int
quicksort(int *array,int begin,int last);

void swap(int *one,int *two);
int main(int argc, char *argv[]) 
{
    int n;
    int i;
    int array[20000];
    scanf("%d",&n); //一共n个元素
    for(i = 0;i<n;i++){
		scanf("%d",&array[i]);
    }
    quicksort(array,0,n-1);
    
    for(i = 0;i<n;i++){
		printf("%d%s",array[i],(i+1 == n)?"":" ");
    }
    
	system("pause");	
	return 0;
}
void swap(int *one,int *two){
	int temp;
	temp = *one;
	*one = *two;
	*two = temp;
}
int
quicksort(int *array,int begin,int last){
	int middle,temp;
	int i,j;
	int pivot;

	if(begin+min<=last){
        middle = (begin+last)/2;
        if(array[begin] > array[middle]){
			swap(&array[begin],&array[middle]);
        }
        if(array[begin] > array[last]){
			swap(&array[begin],&array[last]);
        }
        if(array[middle]>array[last]){
			swap(&array[middle],&array[last]);
        }

        swap(&array[middle],&array[last]); //
		pivot = array[middle];
		i = begin;
		j = last-1;
		while(1){
			while(array[++i]<pivot);
			while(array[--j]>pivot);
			if(i<j){
				swap(&array[i],&array[j]);
			}else{
				break;
			}
		}
		swap(&array[i],&array[last-1]);
		
		quicksort(array,begin,i-1);
		quicksort(array,i+1,last);
	}
	else{
        insertionsort(array,begin,last);
	}
}
int
insertionsort(int *array,int begin,int last){
	int i,j;
	int minimum;
	int temp;
	int loc;
	for(i = begin;i<=last;i++){
		minimum = array[i];
		loc = i;
		for(j = i;j<=last;j++){
			if(array[j] < minimum){
				minimum = array[j];
				loc = j;
			}
		}
		
		swap(&array[i],&array[loc]);
		
	}
}
