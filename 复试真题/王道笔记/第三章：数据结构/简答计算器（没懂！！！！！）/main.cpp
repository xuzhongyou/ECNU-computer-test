#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

char str[220];
int mat[][5]={
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};
stack<int> op;//�����ջ
stack<double> in;//����ջ
void getOp(bool &reto,int &retn,int &i)
{
    if(i==0&&op.empty()==true)
    {
        reto=true;
        retn=0;
        return;
    }
    if(str[i]==0)
    {
        reto=true;
        retn=0;
        return;
    }
    if(str[i]>='0'&&str[i]<='9')
    {
        reto =false;
    }
    else {
        reto=true;
        if(str[i]=='+')
            retn=1;
        else if(str[i]=='-')
            retn=2;
        else if(str[i]=='*')
            retn=3;
        else if(str[i]=='/')
            retn=4;
        i+=2;
        return;
    }
    retn=0;
    for(;str[i]!=' '&&str[i]!=0;i++)
    {
        retn*=10;
        retn+=str[i]-'0';
    }



    if(str[i]==' ')
    {
        i++;
    }
    return;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
