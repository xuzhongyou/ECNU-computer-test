#include <stdio.h>
#include <stdlib.h>
int numbers =1;
int number[51];
int
cow(int year);
int
initcorw();
int
main(int argc, char *argv[])
{
	int year;
	initcorw();
	while(scanf("%d",&year)){
		if(year == 0){
			break;
		}
		printf("%d\n",number[year]);
	}
//	system("pause");
	return 0;
}
/**递归解答问题
int
cow(int year){
	int a;
	if(year<4){
		return 1;
	}
	numbers += year-3;
	a = year-3;
	while(a){
		cow(a--);
	}
}
*/
/*打表解答问题*/
int
initcorw(){
	int i;
	number[0] = 0;
	number[1] = 1;
	number[2] = 1;
	number[3] = 1;
	for(i = 4;i<=50;i++){
		number[i] = number[i-1]+number[i-3];
	}
}
