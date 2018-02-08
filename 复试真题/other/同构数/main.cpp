#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int pow1(int x)
{
    int y=1;
    for(int i=0;i<x;i++)
        y*=10;
    return y;
}

bool isTongGou(int n)
{
	int tmp=n*n,j=n;
	int i=0;
	while(j)
    {
        j/=10;
        i++;

    }
    if((tmp%(pow1(i)))==n)
        return true;
    else return false;

}
int main()
{
	int i;
	int j;
	for(i = 5,j=0;i<=1000;i++)
	{
		if(isTongGou(i))
		{
			j++;
			printf("%5d",i);
			if((j==5))
			{
				printf("\n");//»»ÐÐ
				j=0;
			}
		}
	}


	getchar();
	return 0;
}
