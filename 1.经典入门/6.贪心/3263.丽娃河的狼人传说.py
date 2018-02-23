"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3263
@Website:http://acm.ecnu.edu.cn/problem/3263/
"""
"""
丽娃河是华师大著名的风景线。但由于学校财政紧缺，丽娃河边的路灯年久失修，一到晚上就会出现走在河边要打着手电的情况，不仅非常不方便，而且影响安全：已经发生了大大小小的事故多起。
方便起见，丽娃河可以看成是从 1 到 n 的一条数轴。为了美观，路灯只能安装在整数点上，每个整数点只能安装一盏路灯。经专业勘测，有 m 个区间特别容易发生事故，所以至少要安装一定数量的路灯，

请问至少还要安装多少路灯。
Input
    第一行一个整数 T (1≤T≤300)，表示测试数据组数。

    对于每组数据：

        第一行三个整数 n,m,k (1≤n≤103,1≤m≤103,1≤k≤n)。

        第二行 k 个不同的整数用空格隔开，表示这些位置一开始就有路灯。

        接下来 m 行表示约束条件。第 i 行三个整数 li,ri,ti 表示：第 i 个区间 [li,ri] 至少要安装 ti 盏路灯 (1≤li≤ri≤n,1≤ti≤n)。

Output
    对于每组数据，输出 Case x: y。其中 x 表示测试数据编号（从 1 开始），y 表示至少要安装的路灯数目。如果无解，y 为 −1。
Examples
    input
        3
        5 1 3
        1 3 5
        2 3 2
        5 2 3
        1 3 5
        2 3 2
        3 5 3
        5 2 3
        1 3 5
        2 3 2
        4 5 1

    output
        Case 1: 1
        Case 2: 2
        Case 3: 1
"""
# 算法思想：
# 主要思想是，把区间按照右端点排序，然后从右开始安装路灯，
# 因为是按照右区间端点排序的，所以当前安装的路灯一定会对后续区间产生增益作用；
T = int(input())
for i in range(T):
    N, M, K = map(int, input().split(' '))
    light = [0] * (N+1)
    lighted = list(map(int, input().split(' ')))
    cond = []
    for val in lighted:
        light[val] = 1
    for _ in range(M):
        cond.append(list(map(int, input().split(' '))))
    sorted(cond, key= lambda x: x[1])

    flag = True
    install_total = 0
    for j in range(M):
        l , r, t = cond[j][0], cond[j][1], cond[j][2]
        if t > (r - l + 1): # 如果区间至少安灯数比区间长度大
            flag = False
            break
        installed = sum(light[l:r+1]) # 统计区间已经安装的灯的数目

        if installed < t:
            remain = t - installed # 安装剩余的灯
            install_total += remain
            for k in range(r, l-1, -1):
                if light[k] == 0:
                    light[k] = 1
                    remain -= 1
                if remain == 0:
                    break
    if flag:
        print('Case {n}: {t}'.format(n=i+1, t=install_total))
    else:
        print('Case {n}: -1'.format(n=i+1))

# C++ solution
"""
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000+5
using namespace std;
int n,m,k;
bool light[MAX];
struct Seg{
    int l,r,t;
}seg[MAX];
bool cmp(Seg a,Seg b)
{
    if(a.r==b.r) return a.l<b.l;
    else return a.r<b.r;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++) light[i]=0;//init
        for(int i=1;i<=k;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            light[tmp]=1;
        }
        for(int i=1;i<=m;i++) scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].t);
        sort(seg+1,seg+m+1,cmp);
        int ans=0;
        int flag=1;
        for(int i=1;i<=m;i++)
        {
            if( seg[i].t > seg[i].r-seg[i].l+1 )//输出-1
            {
                printf("Case %d: -1\n",kase);
                flag=0;
                break;
            }
            for(int p=seg[i].l;p<=seg[i].r;p++){
                if(light[p]) seg[i].t--;
                if(seg[i].t<=0) break;
            }//查找当前区间内已有路灯
            if(seg[i].t>0)//加装路灯
            {
                for(int p=seg[i].r;p>=seg[i].l;p--)
                {
                    if(!light[p])
                    {
                        light[p]=1;
                        ans++;
                        seg[i].t--;
                    }
                    if(seg[i].t<=0) break;
                }
            }
        }
        if(flag) printf("Case %d: %d\n",kase,ans);
    }
}
"""
