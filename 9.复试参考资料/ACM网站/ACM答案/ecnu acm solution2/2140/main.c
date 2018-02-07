#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct NODE{
	int data;
	struct NODE *next;
}NODE;
int main(int argc, char *argv[]) 
{
	int C;
	int temp;
	int i,j;
	int M,N;
	NODE *array;
	NODE *p;
	NODE *q;
	array = (NODE*)malloc(sizeof(NODE));
	scanf("%d",&C);
    while(C--){

		scanf("%d %d",&N,&M); //n line m list
		p = array;
		for(i = 0; i<N*M;i++){
			scanf("%d",&temp);
			q =(NODE*)malloc(sizeof(NODE));
			q->data = temp;
			q->next = NULL;
			p->next = q;
			p = p->next;
		}
        p = array;
		for(i = 0; i<N*M;i++){
			scanf("%d",&temp);
			p->next->data +=temp;
			p = p->next;
		}
		p = array;
		for(i = 0;i<N;i++){
			for(j = 0;j<M;j++){
				printf("%d%c",p->next->data,(j == M-1)?'\n':' ');
				p = p->next;
			}
		}
    }
    
	//system("pause");
	return 0;
}
