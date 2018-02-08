"""
@Time:2018/1/31 14:56
@Author:xuzhongyou
"""
#即寻找两个特定节点间最短的路径长度
#Floyd算法
#第一行数据是两个整数N,M。N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M表示成都有几条路
#接下来M行，每行包括3个整数A,B,C,表示AB之间有一条路，需要c分钟走过这条路
#初始化矩阵，并不影响结果 ，初始化2维（矩阵）数组

#可以用这种方式去初始化一个2维矩阵,自己到自己
# ans = [[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1]]

# ans = [[-1]*4 for i in range(4)]
ans = [[-1 for col in range(5)] for row in range(5)]
#这个影响吗
# for i in range(5):
#     ans[i][i] = 0
inputs = input().split(' ')

n = int(inputs[0])
m = int(inputs[1])
for i in range(m):
    inputs = input().split(' ')
    a = int(inputs[0])
    b = int(inputs[1])
    c = int(inputs[2])
    ans[a][b] = ans[b][a] = c
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if ans[i][k] == -1 or ans[k][j] == -1:
                continue
            if ans[i][j] == -1 or ans[i][k]+ans[k][j]<ans[i][j]:
                ans[i][j] = ans[i][k]+ans[k][j]
print(ans[1][n])

# 3 3
# 1 2 5
# 2 3 5
# 3 1 2