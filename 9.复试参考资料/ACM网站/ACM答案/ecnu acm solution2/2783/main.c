#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define NUL '\0'
#define TRUE 1;
#define FALSE 0;
char calc_diff(char pri_vlaue,char value );
int check_re(char *flag,char value);
int main(int argc, char *argv[]) 
{
    int T;
	scanf("%d",&T);
	
	char flag[3001] = {0};
	int count = 0;
	char ch_pri = '0';
	int value;
	char ch;
	while(T--){
		value = 1;
		count = 0;
        scanf("%c",&ch_pri);
		//printf("%c\n",ch_pri);
		while(scanf("%c",&ch) != '\n'){
			//printf("%c\n",ch);
			flag[count] = calc_diff(ch_pri,ch);
			ch_pri = ch;
			if(check_re(flag,flag[count])){
				printf("Not jolly\n");
				value = 0;
				break;
			}
			count++;
		}
		if(value){
            printf("Jolly\n");
		}
		
		
	}
	system("pause");	
	return 0;
}

/*return the count with difference value */
char calc_diff(char pri_value,char value ){
	//printf("abs%d\n",abs(pri_value-value));
	return abs(pri_value-value)+'0';
}
/*if value in falg array ,return 1*/
int check_re(char *flag,char value){
	int *p = flag;
	while(*p != NUL){
		if(*p == value){
			return TRUE;
			p++;
		}
	}
	return FALSE;
}











