#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void
sort(int *data,int count);
int main(int argc, char *argv[])
{
	int n;
	int temp;
	while(scanf("%d",&n)!= EOF){
		int data[100];
		int i= 0;
		int count = 0;
		while(n--){
			scanf("%d",&temp);
			data[count++] = temp;
		}
		sort(data,count);
		for(i = 0; i<count ;i++){
			printf("%d%c",data[i],((i+1) == count)?'\n':' ');
		}
	}
	return 0;
}
void
sort(int *data,int count){
	int i,j,temp;
	for(i = 0;i<count;i++){
		for(j = 0;j<i;j++){
			if(abs(*(data+i))<abs(*(data+j))){
				temp = *(data+i);
				*(data+i) = *(data+j);
				*(data+j) = temp;
			}
		}
	}

}


