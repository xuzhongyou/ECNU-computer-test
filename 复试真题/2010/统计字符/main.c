#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i;
    char str[10000];
    int charNum,Num,other;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            gets(str);
            int len=strlen(str);
            charNum=0;
            Num=0;
            other=0;
            for(i=0;i<len;i++)
            {
                if(str[i]>='0'&&str[i]<='9')
                    Num++;
                else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
                    charNum++;
                else other++;
            }
            printf("Num=%d,charNum=%d,other=%d\n",Num,charNum,other);
        }

    }
    printf("Hello world!\n");
    return 0;
}
