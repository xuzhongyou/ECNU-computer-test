#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define ISYEAP(x) ((x%4==0)&&(x%100!=0))||(x%400==0)?1:0

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
            Month++;
            Day=1;
            if(Month>12)
            {
                Month=1;
                Year++;
            }
        }
    }
};
int buf[3001][13][32];
char monthName[13][20]={
"",
"January",
"February",
"Marth",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December"
};
char weekName[7][20]={
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday",
"Sunday"
};
int main()
{
    Date tmp;
    int cnt=0;
    tmp.Day=1;
    tmp.Month=1;
    tmp.Year=0;
    while(tmp.Year<3001)
    {
        buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
        tmp.nextDay();
        cnt++;
    }
    int d,y;
    char s[20];
    while(scanf("%d%s%d",&d,s,&y)!=EOF)
    {
        int i;
        for(i=1;i<13;i++)
        {
            if(strcmp(s,monthName[i])==0)
                break;
        }
        int days=buf[y][i][d]-buf[2016][2][22];
        puts(weekName[(days%7+7)%7]);
    }
    return 0;
}
