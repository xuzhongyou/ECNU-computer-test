#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char* a,char*b)
{
	if(*a!=*b)
	{
		char t=*a;
		*a=*b;
		*b=t;
	}
}
void reserve(char*first,char*last)
{
	int left=0,right=last-first-1;
	while(left < right)
	{
		swap(first++,--last);
		++left;
		--right;
	}
}
//下一个排列，有重复的字符也可。
//算法：从右到左找到第一个 A[i]<A[i+1]的数，A[i]
// 在从右到左找到第一个A[i]<A[j]的数，A[j]
//交换A[i] A[j],然后倒置[i+1,last)这个区间，OK
bool next_permutation(char *first,char *last)
{
	if(first==last || first+1 ==last) return false;
	char *left=last-1;
	for(;;)
	{
		--left;
		if(*left < *(left+1))
		{
			char* right=last-1;
			while(!(*left < *right)) --right;
			swap(left,right);
			reserve(left+1,last);
			return true;
		}
		if(left == first)
		{
			reserve(first,last);
			return false;
		}
	}
}
int main(void) {
	char s[]="133"; //原始字符串必须升序排序
	int i=0;
	do{
		printf("%d: %s\n",++i,s);
	}while(next_permutation(s,s+strlen(s)));
	return 0;
}

