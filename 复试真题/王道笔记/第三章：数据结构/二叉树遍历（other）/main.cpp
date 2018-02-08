#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s1[101],s2[101];
int a[101];
int k;
void fen(char *s2,int l,int h);
int main()
{

      int i,j;
      while( scanf("%s %s",s1,s2) != EOF){
             k = -1;
             int ii=strlen(s1),jj=strlen(s2);
             for(i = 0;i <ii ;i++){
                   for(j = 0;j < jj;j++){
                         if(s1[i] == s2[j]) a[i] = j;
                         }
                   }

             fen(s2,0,strlen(s2) - 1);

             printf("\n\n");
             }
             return 0;
}

void fen(char *s2,int l,int h){
     int n;
     if(h < l) return ;
     if(h - l > 0) k++;
     n = a[k];
     if(l == h) {
          printf("%c %d   ",s2[h],k);
          k++;
          return ;
          }
     fen(s2,l,n-1);
     fen(s2,n+1,h);
     printf("%c %d   ",s2[n],k);
     }
