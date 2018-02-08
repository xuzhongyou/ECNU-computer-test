"""
@Time:2018/2/1 13:58
@Author:xuzhongyou
"""
#迪杰斯特拉算法：只能求某特定结点到其他所有节点的最短路径长度，即单源最短路径问题。
#算法流程：
# 初始化，集合k中加入结点1，结点1到结点1最短距离为0，到其他结点为无穷
#遍历与集合k中结点直接相连的边，u属于集合k,v不属于集合k，计算结点1出发按照已经得到的最短路径到达u，再由u经过该边到达v的路径长度。
#比较所有与集合k中结点直接相邻的非集合k结点该路径长度路径长度最小的结点被确认为下一个最短路径确定的结点。·

#题目：给点n个，m条无向边，每条边都有长度d和花费p,给你起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则找花费最少的
#输入n,m点的编号为1-n，然后是m行，每行四个数abdp，表示ab之间有一条边，长度d，花费p，最后一行是两个数，s，t表示起点和重点

#注意：单独一个结构体不能不能表示连通的情况


##准备好数据
##
Dist=[-1]*100#代表的就是最短距离
Mark=[-1]*100#表示该节点已经放入到集合k中
Cost=[0]*100
edge_list= []
for i in range(100):
    edge_list.append([])
#这边可以用元组来替换
class edge:
    def __init__(self,next_,c,cost):
        self.next_ = next_
        self.c = c
        self.cost = cost
inputs = input().split(" ")
n = int(inputs[0])
m = int(inputs[1])
for i in range(m):
    inputs = input().split(" ")
    a = int(inputs[0])
    b = int(inputs[1])
    c = int(inputs[2])
    cost = int(inputs[3])
    edge_list[a].append(edge(b,c,cost))
    edge_list[b].append(edge(a,c,cost))
##
inputs = input().split(" ")
S = int(inputs[0])
T = int(inputs[1])
newp = S
Mark[newp] = 1
Dist[newp] = 0
for i in range(1,n):#仅表示循环的次数，没有实际意义
    for j in range(len(edge_list[newp])):#遍历k集合与其之间相邻的节点
        next_ = edge_list[newp][j].next_
        c = edge_list[newp][j].c
        cost = edge_list[newp][j].cost
        if Mark[next_] == 1:continue #直接相连的仍然是K集合的跳过
        if Dist[next_] == -1 or Dist[next_]>Dist[newp]+c or Dist[next_]==Dist[newp]+c and Cost[next_]>Cost[newp]+cost:
            Dist[next_] = Dist[newp]+c
            Cost[next_] = Cost[newp]+cost
    #更新之后，选出新的newp
    min_ = 123123123123
    for j in range(n):
        if Mark[j] == 1:continue
        if Dist[j] == -1 :continue
        if Dist[j]<min_:
            min = Dist[j]
            newp = j
    Mark[newp] = 1
print(Dist[T],Cost[T])

# 3 2
# 1 2 5 6
# 2 3 4 5
# 1 3