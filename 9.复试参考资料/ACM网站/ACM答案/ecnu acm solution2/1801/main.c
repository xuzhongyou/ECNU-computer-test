#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAXN 100001
#define NUL '\0'
static int head = 0;
static int tail = 0;
int
queue[MAXN];
int
enqueue(int value);
int
dequeue();
int
equal(char *string_1,char *string_2);
char *
myStrncpy(char *dest, const char *src, size_t n);
int main(int argc, char *argv[]) 
{
   	int i;
	int q;
	int value;
	char string[100];
	char temp[100];
	scanf("%d",&q);
	while((i = getchar())!=EOF && i!='\n')
		;
	while(q--){
		for(i = 0;i<7;i++){ // temp store the flag of enqueue or dequeue
			temp[i] = getchar();
		}
		temp[i] = NUL;
		if(equal(temp,"enqueue")){
            scanf("%d",&value);
           	while((i = getchar())!=EOF && i!='\n') // clear cache
				;
			printf("%d\n",enqueue());
		}
		if(equal(temp,"dequeue")){
           	while((i = getchar())!=EOF && i!='\n') //clear cache
				;
		    printf("%d\n",dequeue());
		}
	}
	return 0;
}
int equal(char *string_1,char *string_2){
	if(strcmp(string_1,string_2) == 0){
		return 1;
	}
	return 0;
}
/*into queue */
int
enqueue(int value){
	tail = (tail+1)%MAXN;
	if(tail == head){
		if(tail ==0) tail = MAXN-1;
		else tail--;
		return -1;  // enqueue fails
	}
	queue[tail] = value;
	return 0;  //succeed
}
/*exit queue*/
int
dequeue(){
	int value;
	if(head == tail){
		return -1;//dequeue fails
	}
	head = (head+1) %  MAXN;  // store the value of exit queue
	value = queue[head];
	return value;
	
}
