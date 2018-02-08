#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int fun(int a,int b)//前面的数大
{
    int cnt=0;
    do{
        a/=b;
        cnt++;
    }while(a%b==0);
    return cnt;
}
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int b1,q1,n1,b2,q2,n2;
            scanf("%d%d%d%d%d%d",&b1,&q1,&n1,&b2,&q2,&n2);
            int cnt1=b1*q1,cnt2=b2*q2;
            if(b1==b2&&q1==q2)
            {
                printf("%d\n",max(n1,n2));
            }
            else if(gcd(min(cnt1,cnt2),gcd(cnt1,cnt2))==min(cnt1,cnt2))
            {
                if(b1==q2&&b2==q1)
                {
                    if(gcd(b1,b2)==1&&gcd(q1,q2)==1)//两两互质只有一个
                        printf("%d\n",n1+n2-1);
                    else
                    {
                       puts("buhui");//如果类似于4 2 2 2 4 2
                    }
                }
                else if(b1!=b2&&gcd(b1*q1,b2)==b1*q1)//第一组两个可以造出第二个数
                {
                    if(gcd(b2/b1/q1,q1)!=q1&&b2!=b1*q1)
                    {
                        printf("%d\n",n1+n2);
                    }
                    else if(gcd(q1,q2)!=min(q1,q2))
                    {
                        printf("%d\n",n1+n2-1);
                    }
                    else
                    {
                        if(gcd(q1,q2)==q1)
                        {
                            if(b2%b1==0)
                            {
                                int ans=fun(q2,q1),ans1=fun(b2/b1,q1);
                                //printf("ans=%d %d\n",ans,ans1);
                                int jian=0,n1S=n1-1;
                                if(n1S>=ans1)
                                {
                                    n1S-=ans1;
                                    jian++;
                                    for(int i=ans,j=1;i<=n1S&&j<=n2-1;i+=ans,j++)
                                    {
                                        //printf("%d %d %d\n",n1S,i,ans);
                                        jian++;
                                    }
                                }
                                printf("%d\n",n1+n2-jian);
                            }
                            else
                            {
                                int ans=fun(q2,q1),ans1=fun(b2*q2/b1,q1);
                                printf("ans=%d %d\n",ans,ans1);
                                int jian=0,n1S=n1-1;
                                if(n1S>=ans1)
                                {
                                    n1S-=ans1;
                                    jian++;
                                    for(int i=ans,j=1;i<=n1S&&j<=n2-2;i+=ans,j++)
                                    {
                                        printf("%d %d %d\n",n1S,i,ans);
                                        jian++;
                                    }
                                }
                                printf("%d\n",n1+n2-jian);
                            }
                        }
                        else{
                            printf("%d\n",n1+n2);
                        }
                    }
                }
                else if(b1!=b2&&gcd(b2*q2,b1)==b2*q2)//第二组两个可以造出第1个数
                {
                    if(gcd(b1/b2/q2,q2)!=q2&&b1!=b2*q2)
                    {
                        printf("%d\n",n1+n2);
                    }
                    else if(gcd(q1,q2)!=min(q1,q2))
                    {
                        printf("%d\n",n1+n2-1);
                    }
                    else
                    {
                        if(gcd(q1,q2)==q2)
                        {
                            if(b1%b2==0)
                            {
                                int ans=fun(q1,q2),ans1=fun(b1/b2,q2);
                                int jian=0,n2S=n2-1;
                                if(n2S>=ans1)
                                {
                                    n2S-=ans1;
                                    jian++;
                                    for(int i=ans,j=1;i<=n2S&&j<=n1-1;i+=ans,j++)
                                    {
                                        jian++;
                                    }
                                }
                                printf("%d\n",n1+n2-jian);
                            }
                            else{
                                int ans=fun(q1,q2),ans1=fun(b1*q1/b2,q2);
                                int jian=0,n2S=n2-1;
                                //printf("ans=%d %d\n",ans,ans1);
                                if(n2S>=ans1)
                                {
                                    n2S-=ans1;
                                    jian++;
                                    for(int i=ans,j=1;i<=n2S&&j<=n1-2;i+=ans,j++)
                                    {
                                        jian++;
                                    }
                                }
                                printf("%d\n",n1+n2-jian);
                            }
                        }
                        else{
                            printf("%d\n",n1+n2);
                        }
                    }
                }
                else if(b1==b2&&q1!=q2)
                {
                    printf("%d\n",n1+n2-1);
                }
                else {
                    printf("%d\n",n1+n2);
                }
            }
            else { printf("%d\n",n1+n2);}
        }

    }
    //cout << "Hello world!" << endl;
    return 0;
}
