#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


char *MyStrcat(char dstStr[200],char srcStr[100]){
	int len1=strlen(dstStr);
	int len2=strlen(srcStr);
	int i=0;
	for(;i<len2;i++){
		dstStr[len1+i]=srcStr[i];
     }
    dstStr[len1+i]=0;
	return dstStr;
}
int main(){
	char dstStr[200],srcStr[100];
	while(scanf("%s%s",dstStr,srcStr)!=EOF){
		printf("%s\n",MyStrcat(dstStr,srcStr));
	}
	return 0;
}
