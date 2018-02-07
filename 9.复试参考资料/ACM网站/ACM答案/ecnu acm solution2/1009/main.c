#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	system("pause");	
	return 0;
}
int solution(int sum,int number,int n,int *time){
	sum += number;
	if(sum == n){
		(*time) ++;
		return 0; //success
	}
	if(sum > n){
		if(number !=0){
			solution(sum-number,number--,n,*time);
		}
	}
	if(sum <n){
		solution(sum,number,n,*time);
	}
	
}
