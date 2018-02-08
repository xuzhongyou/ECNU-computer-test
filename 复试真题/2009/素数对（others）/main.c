#include<stdio.h>
#include<string.h>
int prime[10005];
void init()
{
int i;
int j;
prime[0]=prime[1]=0;//不是素数
prime[2]=1;//是素数
for(i=3;i<=10005;i+=2)
{
prime[i]=1;//是素数
prime[i+1]=0;//不是素数	除0和2之外的偶数都不是素数
}
for(i=3;i<=10005;i+=2)
{
if(prime[i]==1)//是素数
{
j=i+i;
while(j<=10005)
{
prime[j]=0;//不是素数
j+=i;
}
}
}
}
int main()
{
int c;
int n;
init();//初始化
while(scanf("%d",&c)!=EOF)
{
    while(c--)
    {
        scanf("%d",&n);
        int sum=0;
        int i;
        for(i=2;i<=n/2;i++)
        {
            if(prime[i]&&prime[n+1-i])
            {sum++;}
        }
sum*=2;
if(n%2==1)//n为奇数
{
if(prime[n/2+1])
sum+=1;
}
printf("%d\n",sum);
}
}
return 0;
}
