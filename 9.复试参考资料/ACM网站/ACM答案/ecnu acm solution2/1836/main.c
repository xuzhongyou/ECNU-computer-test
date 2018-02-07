#include <stdio.h>
#include <stdlib.h>
/*Sample Input

3+2-5*0

Sample Output

5 中缀表达式转换为后缀表达式之后再计算。
★~~失败的，，只能计算个位数。
*/

void
mid_to_pos(char *mid,char *pos);

int
pri(char ch);

int
comp_pos(char *pos);
#define cton(x) (x-'0')  // 宏定义字符串转换。
int main(int argc, char *argv[]) 
{
    int ch;
	char input[1000];
	char pos_input[1000];//将中缀表达式转换为后缀
	int result;
	int i= 0;
	scanf("%s",input);
	while((ch = getchar()) !=EOF && ch !='\n') ; //★ '\n'
	//printf("test");
	mid_to_pos(input,pos_input); //已转化。
	result = comp_pos(pos_input);
	//puts(pos_input);
	
	#if 0
	while(pos_input[i] !='\0'){
       	result = cton(pos_input[i]) ;
		printf("test%d===\n",result);
		i++;
	}
	#endif
	
	printf("%d",result);
	system("pause");
	return 0;
}
int
comp_pos(char *pos){
	char stack[1000];
	int i = 0,j = 0,k = 0;
	int temp1,temp2;
	char c;
	int result = 0;
	while((c = pos[i++]) !='\0'){
		switch(c){
			case '+':
               	temp2=(stack[--k]-'0');// ★需要先-- 在用k的值。因为进栈的之后k指向顶点的下一个位置
				temp1=(stack[--k]-'0');
				result = temp1+temp2;
			//	printf("test=%d\n",stack[k]-'0');
				stack[k++] = result;
				break;
			case '-':
				temp2=(stack[--k]-'0');
				temp1=(stack[--k]-'0');
				result = temp1 - temp2;stack[k++] = result;
				break;
			case '*':
				result = (stack[--k]-'0') * (stack[--k]-'0');
				stack[k++] = result;
				break;
			case '/':
				temp2=(stack[--k]-'0');
				temp1=(stack[--k]-'0');
				result = temp1 / temp2;stack[k++] = result;
				break;
			default:
				stack[k++] = c;
				//printf("stack[k]%d\n",c-'0');
				break;
		}
	}
	return result;
}

void
mid_to_pos(char *mid,char *pos){
	char stack[1000];
	stack[0] = '$';
	int i = 0,j = 0,k = 0;
	char c;
	while((c = mid[i++]) != '\0'){

		if(isdigit(c)){
		//	printf("isdigit");
			pos[j++] = c;
		}
		else{
			switch(c){
			    case '+':
			    case '-':
			    case '*':
			    case '/':
					while(pri(c) <= pri(stack[k])) pos[j++] = stack[k--]; // 出栈到pos，直到优先级大于栈顶
					stack[++k] = c;
					break;
				case '(':
					stack[++k] = c;
					break;
				case ')':
					while(stack[k] != '(') pos[j++]= stack[k--];
					break;
			}
		}
	}
	while(k>0) pos[j++] = stack[k--];
	pos[j] = '\0';
}
int
pri(char ch){
	switch(ch){
		    case '+':
		    case '-':return 1;
		    case '*':
		    case '/':return 2;
			case '(':
			case ')':return 3;
			case '$':return -1;
	}
}
