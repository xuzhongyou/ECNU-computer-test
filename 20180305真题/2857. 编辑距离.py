"""
@Time:2018/3/7 13:32
@Author:xuzhongyou
"""
# 有两个字符串（仅有英文小写字母组成） A，B。我们可以通过一些操作将 A 修改成 B。
# 操作有三种：1 修改一个字母，2 删除一个字母，3 插入一个字母。现在定义编辑距离为将 A 通过上述操作修改成 B 的最少次数
#先给边界，在转移

#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<algorithm>
# using namespace std;
#
# int dp[1005][1005];
# char str1[1005],str2[1005];
# int main()
# {
#     int n;
#     scanf("%d",&n);
#     while(n--)
#     {
#         int num;
#         scanf("%s",str1);
#         scanf("%s",str2);
#         int len1=strlen(str1),len2=strlen(str2);
#         for(int i=0;i<=len1;i++)
#         {
#             dp[i][0]=i;
#         }
#         for(int i=0;i<=len2;i++)
#         {
#             dp[0][i]=i;
#         }
#         for(int i=1;i<=len1;i++)
#         {
#             for(int j=1;j<=len2;j++)
#             {
#                 if(str1[i-1]==str2[j-1])
#                 {
#                     dp[i][j]=dp[i-1][j-1];
#                 }
#                 else
#                 {
#                     dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
#                 }
#             }
#         }
#         printf("%d\n",dp[len1][len2]);
#     }
#     return 0;
# }


# T = int(input())
# for _ in range(T):
#     n1 = input()
#     n2 = input()
#     len1 = len(n1)
#     len2 = len(n2)
#     # 给初始状态，然后确定转移方程来求解
#     dp = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]
#     for i in range(len1 + 1):
#         dp[i][0] = i
#     for j in range(len2 + 1):
#         dp[0][j] = j
#
#         # 需要注意的是看循环从哪一结点开始的
#     for i in range(1, len1 + 1):
#         for j in range(1, len2 + 1):
#             if n1[i - 1] == n2[j - 1]:
#                 dp[i][j] = dp[i - 1][j - 1]
#             else:
#                 dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
#     print(dp[len1][len2])
