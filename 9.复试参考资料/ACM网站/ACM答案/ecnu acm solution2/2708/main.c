#include <stdio.h>
#include <stdlib.h>
/*digit 0 being typed on the typewriter makes a nice hole in the paper and
you receive a small paper oval as a bonus.
The same happens with some other digits:
4, 6, 9 produce one hole, and 8 produces two touching holes.
The remaining digits just cut the paper without making holes.

The number must be minimal possible and should not have leading zeroes*/
int main(int argc, char *argv[]) 
{
	int h;
	while(scanf("%d",&h)!= EOF){
		if(h == 0){
			printf("1\n");
		}
		else if(h== 1){
			printf("0\n");
		}
		/*h&1 == 1 h is singular*/
		else if(h&1){
   	    	printf("4");
			for(;h!=1;h-=2){
				printf("8");
			}
			printf("\n");
		}else if(!(h&1)){
			for(;h!=0;h-=2){
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
