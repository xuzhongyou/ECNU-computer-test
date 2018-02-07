#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int x;
	struct Node *link;
}Node;

void p_node(Node *p);

void ins_node(int loc,Node *temp,Node *p);
int main(int argc, char *argv[]) 
{
	int n,m;
	int i;
	scanf("%d",&n);
	
	Node *head = (Node*)malloc(sizeof(Node)*n+1);
	Node *p = head;
	for(i = 0;i<n;i++){
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->link = NULL;
		scanf("%d",&(temp->x));
		p->link = temp;
		p = p->link;
 	}
 	//p_node(head);
 	scanf("%d",&m);
 	
 	for(i = 0;i<m;i++){ // insert
 	    int loc;
 	    scanf("%d",&loc);
 	   // printf("loc =%d\n ",loc);
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->link = NULL;
		scanf("%d",&temp->x);

		ins_node(loc,temp,head);
		p_node(head);
 	}
 	

	
	system("pause");	
	return 0;
}

void p_node(Node *p){
	while(p->link !=NULL ){
		printf("%d",p->link->x);
		p = p->link;
		if(p->link !=NULL){
			printf(" ");
		}
	}
	printf("\n");
}
void ins_node(int loc,Node *temp,Node *p){
	while(p->link->x != loc){
		p = p->link;
	}
	temp->link = p->link->link;
	p->link->link = temp;
	
	



}
