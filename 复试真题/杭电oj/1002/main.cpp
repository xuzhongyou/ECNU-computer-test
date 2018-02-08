#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

bool LongPositiveIntegerAddtion(char a[],char b[],char sum[]){
        int flag=0;
        char tmp[1000]="\0";
        bool change=false;
        int la=strlen(a);
        int lb=strlen(b);
        if(la<lb){
                strcpy(tmp,a);
                strcpy(a,b);
                strcpy(b,tmp);
                flag=la;
                la=lb;
                lb=flag;
                change=true;
        }
        sum[la+1]='\0';
        la--,lb--;
        flag=0;
        while(lb>=0){
                sum[la+1]=(a[la]-'0')+(b[lb]-'0')+flag;
                if(sum[la+1]>=10){
                        sum[la+1]-=10;
                        flag=1;
                }
                else flag=0;
                sum[la+1]+='0';
                la--,lb--;
        }
        while(la>=0){
                sum[la+1]=(a[la]-'0')+flag;
                //if(sum[la]>=10){
//                        sum[la]-=10;
//                        flag=1;
//                }由a[la] 求的是sum[la+1]的结果，应该是笔误吧，小心点就是
               if(sum[la+1]>=10){
                        sum[la+1]-=10;
                        flag=1;
                }
                else flag=0;
                sum[la+1]+='0';
                la--;
        }
        sum[0]=flag+'0';
        return change;
}

int main(){
        char a[1000]="\0", b[1000]="\0",sum[1000]="\0";
        int count=0;
        scanf("%d",&count);
        for(int i=1;i<=count;i++){
                //flushall();
                scanf("%s %s",&a,&b);
                bool change  = LongPositiveIntegerAddtion(a,b,sum);
                printf("Case %d:\n",i);
                if( !change )////调整a、b输出顺序
                printf("%s + %s = ",a,b);
                else printf("%s + %s = ",b,a);
        if(sum[0]=='0')
                         printf("%s\n",sum+1);
        else printf("%s\n",sum);
                if(i<count)        printf("\n");
        }
        return 0;
}
