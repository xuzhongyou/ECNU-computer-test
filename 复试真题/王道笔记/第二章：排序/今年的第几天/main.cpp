#include <iostream>
#include <stdio.h>
#include <algorithm>

#define ISYEAP(x) ((x%100!=0)&&(x%4==0))||(x%400)==0?1:0
using namespace std;

int dayOfMonth[13][2]={
{0,0},
{31,31},
{28,29},
{31,31},
{30,30},
{31,31},
{30,30},
{31,31},
{31,31},
{30,30},
{31,31},
{30,30},
{31,31}
};
struct Date{
    int Day;
    int Month;
    int Year;
    void nextDay(){
        Day++;
        if(Day>dayOfMonth[Month][ISYEAP(Year)])
        {
              Day=1;
              Month++;
              if(Month>12)
              {
                  Month=1;
                  Year++;
              }
        }
    }
};

int buf[5001][13][32];
int ABS(int x)
{
    return x<0?-x:x;
}
int main()
{
    Date tmp;
    int cnt=0;
    tmp.Day=1;
    tmp.Month=1;
    tmp.Year=0;
    while(tmp.Year!=5001)
       {
           buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
           tmp.nextDay();
           cnt++;
       }
    int year,days;
    while(scanf("%4d%d",&year,&days)!=EOF)
    {
        Date one;
        one.Year=year;
        one.Month=1,one.Day=1;
        while(--days)
        {
            one.nextDay();
        }
        printf("%04d-%02d-%02d\n",one.Year,one.Month,one.Day);
    }

    return 0;
}
