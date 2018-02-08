#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Node{
Node *lchild;
Node *rchild;
int c;
}Tree[110];

int loc;
Node *creat(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

void postOrder(Node *T)
{
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    printf("%d ",T->c);
}

void preOrder(Node *T)
{
    printf("%d ",T->c);
    if(T->lchild!=NULL)
        preOrder(T->lchild);
    if(T->rchild!=NULL)
        preOrder(T->rchild);

}
void inOrder(Node *T)
{
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    printf("%d ",T->c);
    if(T->rchild!=NULL)
        inOrder(T->rchild);

}
void print(Node *T)
{

    int parentSize=1,childSize=0;
    Node *temp;
    queue<Node*> q;
    q.push(T);
    do{
        temp=q.front();
        printf(" %d ",temp->c);
        q.pop();
        if(temp->lchild!=NULL)
        {
            q.push(temp->lchild);

            childSize++;
        }
        if(temp->rchild!=NULL)
        {

            q.push(temp->rchild);
            childSize++;
        }
        parentSize--;
        if(parentSize==0)
        {
            parentSize=childSize;
            childSize=0;
            printf("\n");
        }
    }while(!q.empty());
}

Node *Insert(Node *T,int x)
{
    if(T==NULL)
    {
        T=creat();
        T->c=x;
        return T;
    }
    else if(x<T->c)
        T->lchild=Insert(T->lchild,x);
    else if(x>T->c)
        T->rchild=Insert(T->rchild,x);
    return T;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        loc=0;
        Node *T=NULL;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            T=Insert(T,x);
        }
        print(T);
        printf("\n");
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}
