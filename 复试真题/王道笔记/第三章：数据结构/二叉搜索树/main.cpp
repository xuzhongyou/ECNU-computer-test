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

Node *creat()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

char str1[25],str2[25];
int siz1,siz2;
char *str;
int *size;

void postOrder(Node *T)
{
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    str[(*size)++]=T->c+'0';
}
void inOrder(Node *T)
{
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    str[(*size)++]=T->c+'0';
    if(T->rchild!=NULL)
        inOrder(T->rchild);
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
    {
        T->lchild=Insert(T->lchild,x);
    }
    else if(x>T->c)
    {
        T->rchild=Insert(T->rchild,x);
    }
    return T;
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
int main()
{
    int n;
    char tmp[12];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        loc=0;
        Node *T=NULL;
        scanf("%s",tmp);
        for(int i=0;tmp[i]!=0;i++)
        {
           T=Insert(T,tmp[i]-'0');
        }
        print(T);
        siz1=0;
        str=str1;
        size=&siz1;
        postOrder(T);
        inOrder(T);
        str1[siz1]=0;
        while(n--)
        {
            scanf("%s",tmp);
            printf("%s\n",tmp);
            Node *T2=NULL;
            for(int i=0;tmp[i]!=0;i++)
            {
               T2= Insert(T2,tmp[i]-'0');
            }
            print(T2);
            siz2=0;
            str=str2;
            size=&siz2;
            postOrder(T2);
            inOrder(T2);
            str2[siz2]=0;
            if(strcmp(str1,str2)==0)
                puts("Yes");
            else puts("NO");
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
