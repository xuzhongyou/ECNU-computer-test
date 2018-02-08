#include <iostream>
#include<stdio.h>
#include <queue>
using namespace std;


char fstr[27],mstr[27];
struct TNode{
    TNode *lchild,*rchild;
    char str;
    TNode()
    {
        lchild=NULL;
        rchild=NULL;
    }
};
int search(char *str,char x) //查找字符串，返回对应的数组下标
{
    int i;
    for(i=0;str[i]!='\0';i++)
        if(str[i]==x) return i;
    return -1;
}
void Fbit(TNode *root,char x) //根据先序遍历数组，判断在目标结点的左边或右边。在叶节点处插入
{
    int mindex,findex;
    mindex=search(mstr,x);
    findex=search(mstr,root->str);
    if(mindex<findex)
    {
       if(root->lchild==NULL)
       {
        root->lchild=new TNode;
        root->lchild->str=x;
        }else Fbit(root->lchild,x);
    }
    else
    {
        if(root->rchild==NULL)
        {
            root->rchild=new TNode;
            root->rchild->str=x;
        }else Fbit(root->rchild,x);
    }
}
void Bbit(TNode *root) //后序遍历输出
{
    if(root==NULL) return;
    Bbit(root->lchild);
    Bbit(root->rchild);
    printf("%c",root->str);
}

void print(TNode *T)
{

    int parentSize=1,childSize=0;
    TNode *temp;
    queue<TNode*> q;
    q.push(T);
    do{
        temp=q.front();
        printf(" %c ",temp->str);
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
    while(gets(fstr))
    {
        gets(mstr);
        int i;
        TNode *root = new TNode;
        root->str=fstr[0];
        for(i=1;fstr[i]!='\0';i++)  //根据先序遍历数组，判断在目标结点的左边或右边。在叶节点处插入
        {
            Fbit(root,fstr[i]);
        }
        print(root);
        Bbit(root);
        printf("\n");
    }
}
