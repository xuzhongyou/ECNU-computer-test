#include <stdio.h>
#include <string.h>

int top;
void f(char a[], char b[], char * c, int starta, int enda, int startb, int endb)
{
        c[++top] = a[starta];
        int i;
        for(i = startb; b[i] != c[top]; ++i);
        int llen = i - startb, rlen = endb - i;
        if(rlen)
                f(a,b,c,enda-rlen+1,enda,i+1,endb);
        if(llen)
                f(a,b,c,starta+1,starta+llen,startb,i-1);
}

int main(void)
{
        char a[26],b[26],c[26];
        while(scanf("%s%s",a,b) != EOF)
        {
                top = -1; int len = strlen(a);
                f(a,b,c,0,strlen(a)-1,0,strlen(b)-1);
                for(int i = len-1; i >= 0; --i)
                        printf("%c",c[i]);
                printf("\n");
        }
    return 0;
}
