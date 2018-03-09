"""
@Time:2018/3/9 13:51
@Author:xuzhongyou
"""

#填充数据，构造无向图
label = []
def fill_Data(n,m):
    data = {}
    for i in range(1,n+1):
        data.setdefault(i,[])
    for i in range(m):
        a,b,c = map(str,input().split())#c表长度，d表花费
        if a not in label:
            label.append(a)
        if b not in label:
            label.append(b)
        data[label.index(a)+1].append((label.index(b)+1,int(c)))
        data[label.index(b)+1].append((label.index(a)+1,int(c)))
    return data
#表示的是节点数，和路径数
n,m = map(int,input().split())
data = fill_Data(n,m)
#表示起点，终点
cs = int(input())
for _ in range(cs):
    Dis = [-1] * 1003
    mark = [False] * 1003
    S,T=map(str,input().split())
    if S not in label or T not in label:
        print(-1)
        continue
    S = label.index(S)+1
    T = label.index(T)+1
    newp = S
    Dis[S]=0
    mark[S]=True
    #遍历n个点，每次加入一个
    for i in range(1,n+1):
        for j in range(len(data[newp])):
            t = data[newp][j][0]#连接的下一个点
            d = data[newp][j][1]#表示距离
            #更新所有与newp相连的Dis[t]
            if mark[t]==True:continue
            if Dis[t]==-1 or Dis[t]>Dis[newp]+d :
                Dis[t]=Dis[newp]+d
        min_ = 1231231231231
        for j in range(1,n+1):
            if mark[j]==True:continue
            if Dis[j]==-1:continue#别忘记这条
            if Dis[j]<min_:
                min_=Dis[j]
                newp = j
        mark[newp]=True
    print(Dis[T])
# 4 5
# 168.120.1.1 168.120.1.2 15
# 168.120.1.1 168.120.1.4 47
# 168.120.1.1 168.120.1.3 10
# 168.120.1.2 168.120.1.4 15
# 168.120.1.3 168.120.1.4 25
# 3
# 168.120.1.1 168.120.1.4
# 168.120.1.3 168.120.1.4
# 168.120.1.3 202.12.12.12
# output
# 30
# 25
# -1

