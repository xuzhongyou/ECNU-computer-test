/*Description

对一个整数(32位无符号整数)进行规则如下的加密：
1. 低16位和高16位互换
2. 此时的低16位按位取反
3. 此时的高16位与低16位进行异或运算，结果存储到高16位
写出一个程序对指定的整数进行加密。

Input

输入有多case，每个case一行，且只有一个整数

Output

对于每个case输出一个整数(16进制形式)，即加密后的整数

Sample Input

1

Sample Output

FFFEFFFF*/

#include <stdio.h>
#include <stdlib.h>
int
test();
int main(int argc, char *argv[]) 
{   
	test();
	return 0;
}
int
prog(){
    	unsigned int value;
	unsigned int value_high_16;
	unsigned int value_low_16;
	while(scanf("%d",&value) !=EOF){
		value_high_16 = value & 0xffff0000;

		value_low_16 = value & 0x0000ffff;

		/*exchange the high value and low value*/
		value = 0x0000000;
		value |= value_low_16<<16;
		value |= value_high_16>>16;

		value_high_16 = value & 0xffff0000;
		value_low_16 = (~value & 0x0000ffff); // negation the low 16 bit

		value_high_16 ^= value_low_16<<16;

		value = 0x0000000;
		value |=value_high_16;
		value |=value_low_16;
		printf("%08X\n",value);
	}
	return 0;

}
int
test(){
	unsigned int value;
	unsigned int value_high_16;
	unsigned int value_low_16;
	while(scanf("%d",&value) !=EOF){
		value_high_16 = value & 0xffff0000;

		value_low_16 = value & 0x0000ffff;

		value_high_16 = ~value_high_16 & 0xffff0000;

		value_low_16 ^= value_high_16>>16;


		value = 0;
		value |=value_high_16>>16;
		value |=value_low_16<<16;
		printf("%08X\n",value);
	}
	return 0;
}



