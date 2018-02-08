#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char data[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    int a,b;
    char str[40];
    while(scanf("%d%s%d",&a,str,&b)!=EOF)
    {
        int len=strlen(str),tmp=0,c=1;
        for(int i=len-1;i>=0;i--)
        {
            int x;
            if(str[i]>='0'&&str[i]<='9')
                x=str[i]-'0';
            else if(str[i]>='a'&&str[i]<='z')
                x=str[i]-'a'+10;
            else if(str[i]>='A'&&str[i]<='Z')
                x=str[i]-'A'+10;
            tmp+=x*c;
            c*=a;
        }
  unsigned char ans[40],size=0;//注意！！！！！默认是signed 必须unsigned
        do{
            ans[size++]=data[tmp%b];
            tmp/=b;
        }while(tmp!=0);
        for(int j=size-1;j>=0;j--)
            printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}
