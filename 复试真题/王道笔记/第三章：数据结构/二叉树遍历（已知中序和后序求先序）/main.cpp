#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s1[101],s2[101];
int a[101];
int k;
char stack[101];
int numOf;
void fen(char *s2,int l,int h);
int main()
{

      int i,j;

      while( scanf("%s %s",s1,s2)!= EOF){

            int s1len=strlen(s1),s2len=strlen(s2);
            k =s1len;
            numOf=0;
             for(i = 0;i < s1len;i++){
                   for(j = 0;j < s2len;j++){
                         if(s1[i] == s2[j]) a[i] = j;
                         }
                   }

             fen(s1,0,strlen(s1) - 1);
            for(int k=s1len-1;k>=0;k--)
            {
                printf("%c",stack[k]);
            }
             printf("\n");
             }
             return 0;
}

void fen(char *s1,int l,int h){
     int n;
     if(h < l) return ;
     if(h - l > 0) k--;
     n = a[k];

     if(l == h) {
          //printf("%c %d ",s1[h],k);
          stack[numOf++]=s1[h];
          k--;
          return ;
          }


     fen(s1,n+1,h);
    fen(s1,l,n-1);
   // printf("%c %d ",s1[n],k);
    stack[numOf++]=s1[n];
     }
