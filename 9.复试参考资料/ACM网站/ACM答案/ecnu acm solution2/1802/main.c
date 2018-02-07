#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int k,i;
	scanf("%d",&k);
	char array[100];
	
	while(k--){
		scanf("%d",&i);
		scanf("%s",&array);
		if(stack(i,array)){
			printf("yes\n");
		}else{
            printf("no\n");
		}
	}

	system("pause");	
	return 0;
}

int stack(int n,char *array){
	int stack[100];
	int top  =0;
	stack[top] = -1; //初始化
	int i;
	int j = 0;
	for(i = 0;i<=n;){
		while(stack[top] != ((int)array[j]-(int)'0')){//不匹配 进栈。
            stack[++top] = ++i;
            
            
            if(i>n){// 所有元素进栈，不匹配，结束。
				break;
            }
		}
		stack[top--] = -1;//匹配到一个。出栈。
		if(++j == n){//匹配完成
		    break;
		}
	}
	if(stack[1] == -1){
		return 1; // 成功
	}
	else return 0;

}
