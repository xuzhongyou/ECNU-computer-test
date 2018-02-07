#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979
#define E 2.718281828459

void calc(int n);
void test(int N);
int main(int argc, char *argv[]) 
{
	int n;
	while(scanf("%d",&n) !=EOF){

	calc(n);
	//test(n);
	}
	
	//system("pause");
	return 0;
}
void test(int N){
	double jiecheng;
	int num;
	int first_number;
	jiecheng = sqrt(2*PI*N) * pow((N/E),N);
	num = log10(jiecheng);
	first_number = jiecheng/pow(10,num);
	printf("%d\n",first_number);
}
void calc(int n){
	int first_number;
	double result;
	result = 0.5* log(2*PI*(double)n)/log(10.0) + (double)n* log((double)n/E)/log(10.0);
	result -= (int)result;
	first_number = exp(result * log(10.0));
	
	switch(n){
		case 0:
			first_number = 1;
			break;
		case 1:
            first_number = 1;
            break;
		case 2:
            first_number = 2;
            break;
		case 3:
            first_number = 6;
            break;
		case 7:
            first_number = 5;
            break;
		case 8:
            first_number = 4;
            break;
	}
	printf("%d\n",first_number);
}
