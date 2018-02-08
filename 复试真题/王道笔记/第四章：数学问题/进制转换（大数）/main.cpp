#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char a[30];
    while(scanf("%s",a)!=EOF)
    {
        int b[30],c[100],len=0;
        for(int i=0;a[i]!=0;i++)
        {
            b[i]=a[i]-'0';
            len++;
        }
        int i=0,cnt=0,j,k;
        while(i<len)
        {
            c[cnt++]=b[len-1]%2;
            k=0;//½èÎ»
            for(j=i;j<len;j++)
            {
                int tmp=b[j];
                b[j]=(b[j]+k)/2;
                if(tmp&1)//ÈôÎªÆæÊý
                    k=10;
                else k=0;
            }
            if(b[i]==0)
                i++;
        }
        for(i=cnt-1;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}
