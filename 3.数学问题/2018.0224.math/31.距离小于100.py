"""
@Time:2018/2/24 15:27
@Author:xuzhongyou
"""
# 31. 距离小于 100！
# 定义函数 NearPoints，计算一组三维坐标点中离原点距离小于 100 的点个数。点的类型定义为：
#
# typedef struct {
#     int x, y, z;
# } Point;

# Input
# 第一行一个整数 n (1≤n≤1000)。
#
# 接下来 n 行每行三个整数 xi,yi,zi (−109≤xi,yi,zi≤109)。点坐标可能重复出现。
#
# Examples
# input
# 4
# 1 2 3
# 50 50 50
# 100 0 0
# 100 100 100
# output
# 2
import math
T = int(input())
count= 0
for i in range(T):
    n,m,k = map(int,input().split(' '))
    if math.sqrt(n**2+m**2+k**2)<100:
        count+=1
print(count)