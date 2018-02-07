#include <stdio.h>
#include <stdlib.h>
int array[100000];

void quick_sort(int arr[], int len);

void quick_sort_recursive(int arr[], int start, int end) ;

void swap(int *x, int *y) ;

comp(void const  *a,void const  *b);
int main(int argc, char *argv[]) 
{
	int n,k;
	int i;
	int loc;
	scanf("%d",&n);
	for(i = 0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//quick_sort(array,n);  // 自定义排序， 效率稍微高，内存稍微高
	qsort(array,n,sizeof(int),comp); // 系统排序 ，效率稍微低 内存稍微低
	scanf("%d",&k);
	for(i = 0;i<k;i++){
		scanf("%d",&loc);
		printf("%d\n",array[loc-1]);
	}
	system("pause");	
	return 0;
}
int comp(void const  *a,void const  *b){
	if(*(int *)a >*(int *)b ){ // 转换完类型之后要记得加* 。。
		return 1;
	}
	if(*(int*)a <*(int *)b){
		return -1;
	}
	if(*(int *)a == *(int *)b){
		return 0;
	}
}
void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;//這是為了防止宣告堆疊陣列時當機
	int mid = arr[end]; // 对比值放在中间
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}
