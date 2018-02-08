#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

char str[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    char aa[100],bb[100];
    while(scanf("%s%s",aa,bb)!=EOF)
    {
        int a[100]={0},b[100]={0};
        int len1=strlen(aa),len2=strlen(bb),len3;
        for(int i=0;i<len1;i++)
        {
            if(aa[i]>='0'&&aa[i]<='9')
                a[len1-i-1]=aa[i]-'0';
            if(aa[i]>='a'&&aa[i]<='z')
                a[len1-i-1]=aa[i]-'a'+10;
            if(aa[i]>='A'&&aa[i]<='Z')
                a[len1-i-1]=aa[i]-'A'+10;
        }
        for(int i=0;i<len2;i++)
        {
            if(bb[i]>='0'&&bb[i]<='9')
                b[len2-i-1]=bb[i]-'0';
            if(bb[i]>='a'&&bb[i]<='z')
                b[len2-i-1]=bb[i]-'a'+10;
            if(bb[i]>='A'&&bb[i]<='Z')
                b[len2-i-1]=bb[i]-'A'+10;
        }
        int c=0;
        len3=max(len1,len2);
        //for(int i=0;i<len3;i++)
          //  printf("%d ",a[i]);
       // printf("\n");
        for(int i=0;i<len3;i++)
        {
            a[i]=a[i]+b[i]+c;
            if(a[i]>15)
            {
                c=a[i]/16;
                a[i]=a[i]%16;
            }
            else c=0;
        }
        //for(int i=0;i<len3;i++)
         //   printf("%d ",a[i]);
        //printf("%d",c);
        //printf("\n\n");
        if(c>=1)
        {
            a[max(len1,len2)]=c;
            len3=max(len1,len2)+1;
        }

        for(int i=len3-1;i>=0;i--)
        {
            int tmp=a[i];
            printf("%c",str[tmp]);
        }
        printf("\n");
    }
    //cout << "Hello world!" << endl;
    return 0;
}
