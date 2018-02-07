#include <stdio.h>
#include <stdlib.h>
#include "string.h"


char *
reversal(char * origin);

char *
mulitiplication(char *multiplier,char *multiplicand);

int ctoi(char c);

void
irtocr(int* array,char* result,int len);
int main(int argc, char *argv[]) 
{
	int n;
	char origin1[501];
	char origin2[501];
	scanf("%d",&n);
	
	while(n--){
		scanf("%s %s",origin1,origin2);
		printf("%s\n",mulitiplication(origin1,origin2));
	}
	
	system("pause");	
	return 0;
}
//大数据乘法。
char *
mulitiplication(char *multiplier,char *multiplicand){
	int ultimate[1001];  //最终结果
	int len = 0;  //结果总长度
	reversal(multiplier);
	reversal(multiplicand);
	int i,j,k;  //循环控制变量
	int multicarry,addcarry,temp1,temp2,m,n;
	m =strlen(multiplicand); //被乘数的长度
	n =strlen(multiplier);// 乘数的长度
	memset(ultimate,0,sizeof(int)*1001);
	char result[1001];
	if( !strcmp(multiplier,"0") || !strcmp(multiplicand,"0") ){  //如果有一个是0 则不再计算。
		return "0";
	}
	
	for(i = 0;i<strlen(multiplier);i++){
		multicarry = 0;
		addcarry = 0;
		for(j = 0;j<strlen(multiplicand);j++){
			temp1 = ctoi(multiplicand[j]) * ctoi(multiplier[i]) +multicarry;// 相乘result maybe大于10
		//	printf("temp1 = :%d \n",temp1);
			multicarry = temp1 / 10;  //单独计算乘法进位
			temp1 = temp1%10;// 取余数
			temp2 = ultimate[i+j] +temp1 +addcarry;  //上一次进位和当前乘法取得数值 和上一次加法进位
			addcarry = temp2 /10;  //本次加法进位  此次加法进位已经包括此次的乘法进位。
			ultimate[i+j] = temp2 %10;
		}
		ultimate[i+m] = multicarry + addcarry; // 将一位乘数乘以被乘数的结果完毕之后的最高进位保存。
	/*	printf("单次乘法结果：");
		for(k = i+m;k>=0;k--){
			printf("%d",ultimate[k]);
		}
		printf("\n");
		*/
	}
	if(ultimate[i+m-1] == 0){
		len = i+j-1;
	}if(ultimate[i+m-1] !=0){
		len = i+j;
	}
	irtocr(ultimate,result,len);
	return reversal(result);
}

// 将一个整形数组转换为char 类型数组。
void
irtocr(int* array,char* result,int len){
	//char result[1001];
	int i;
//	printf("len = %d\n",len);
	for(i = 0;i< len ;i++){
		result[i] = (char)(array[i]+'0');
	}
	
	result[i] = '\0';
	//puts(result);

}
//char 转换为int
int ctoi(char c){
	return c-'0';
}
//反转字符串。
char *
reversal(char * origin){
	int len = strlen(origin);
	//printf("reversal len = %d \n",len);
	int i = 0;
	int temp;
	while((len-1)>=i){
		temp = origin[i];
		origin[i] = origin[len-1];
		origin[len-1] = temp;
		len--;i++;
	}
	//printf("reversal ：");
	//puts(origin);
	return origin;
}
