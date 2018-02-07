#include <stdio.h>
#include <stdlib.h>

int fn[1001] = {0,1,1,2,3,1};
char map[101][101];
int H,W,T;
int main(int argc, char *argv[]) 
{
	int i,j; // 循环变量
	int ch;
	int hp = 0; //生命值。
	int a = 0,b = 0; //当前坐标
	int dir; // 本次移动的方向。
	scanf("%d %d %d",&H,&W,&T); // 初始化地图范围次数。
	while((ch = getchar()) !=EOF && ch!='\n')
			;
	
	for(i = 0;i<H;i++){ // init the map
		for(j = 0;j<W;j++){
			scanf("%c",&map[i][j]);
		}
		while((ch = getchar()) !=EOF && ch!='\n')
			;
	}

	if(map[0][0] != '.'){
		 hp = map[0][0]-'0';
	}else{
         hp = 0;
	}
	for(i = 0;i<T;i++){// 循环T时刻。
        dir  = fn[i%6];
        hp +=move(&a,&b,dir);
        
	}
	printf("%d",hp);
	
	system("pause");	
	return 0;
}

int move(int *a,int *b,int dir){
	if(dir == 0){ // up
		if(*a == 0){// 以达到顶部边缘。
            return move(a,b,1);
		}
		*a = *a -1;
		
	}if(dir == 1){ // right
		if(*b == (W-1)){// 以达到右部边缘。
            return move(a,b,2);
		}
		*b = *b +1;
	}if(dir == 2){  // down
		if(*a == (H-1)){// 以达到低部边缘。
            return move(a,b,3);
		}
		*a = *a +1;
	}if(dir == 3){  //left
		if(*b == 0){// 以达到左部边缘。
            return move(a,b,1);
		}
		*b = *b-1;
	}
	if(map[*a][*b] >='0' && map[*a][*b] <='9'){
		return map[*a][*b]-'0';
	}
	else return 0;
}
