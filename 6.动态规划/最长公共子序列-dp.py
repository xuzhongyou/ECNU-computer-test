"""
@Time:2018/2/22 16:48
@Author:xuzhongyou
"""
#LCS,另一个经典的动态规划问题，最长公共子序列
#思路：
#较小规模情况下，可以求解
#假设已求dp[i][j]   0<i<x,0<j<y，如何推出dp[x][y]
#dp[0][j] = 0
#dp[i][0] = 0
#dp[i][j] = dp[i-1][j-1]+1 if s1[x]== s2[y]
#dp[i][j] = max{dp[i-1][j],dp[i][j-1]} if s1[x]!=s2[y]

#08上交 coincidence
str1 = 'abcead'
str2 = 'cxbceydz'
len1 = len(str1)
len2 = len(str2)
dp = [[0]*10 for i in range(10)]
dp[0] = [0]*10
for i in range(len(dp)):
    dp[i][0] = 0
for i in range(len1+1):
    for j in range(len2+1):
        if str1[i-1] != str2[j-1]:
            dp[i][j] = max(dp[i][j-1],dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j-1]+1
print(dp[len1][len2])