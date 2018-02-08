"""
@Time:2018/1/26 9:40
@Author:xuzhongyou
"""
#首先什么是生成树：包含所有节点和部分边，但不会产生回路的子图称为生成树
#最小生成树指的是生成树中权值的和最小的那棵
#最小生成树的应用：通信基站光缆使所有的基站间可以直接或间接通信，最少需要多少长的光缆
#Krustal算法：
#1.初始时所有结点属于孤立的集合
#2.边权递增顺序遍历所有的边，若遍历到的边两个顶点仍分属不同的集合，则确认该边为最小生成树上的一条边，并将这两个顶点分属的集合合并。
#3.遍历完所有边，原图上所有节点属于同一个集合则被选取的边和原图中的所有节点构成最小生成树，否则原图不连通，最小生成树不存在
#仍然可以用并查集来操作

#题目：列出了任意两村庄间的距离，畅通工程的目标是使全省任何两个村庄间都可以实现公路交通，求铺设的公路总长度为最小
#输入：3
#     1 2 1
#     1 3 2
#     2 3 4
class Node:
    def __init__(self,a,b,cost):
        self.a = a
        self.b = b
        self.cost = cost

n = int(input())
result = [-1]*(n+1)
Node_list = []
def findroot(i):
    if result[i] ==-1:
        return i
    else:
        return  findroot(result[i])

for i in range(int(n*(n-1)/2)):
    nums = input().split(' ')
    node = Node(int(nums[0]),int(nums[1]),int(nums[2]))
    Node_list.append(node)
Node_list = sorted(Node_list,key=lambda node: node.cost)
ans = 0
for node in Node_list:
    a = findroot(node.a)
    b = findroot(node.b)
    #巧妙的利用并查集解决回路问题，回路的出现并不会增加权重
    #但是无法解决无法生成最小生成树的情况
    if a != b:
        result[a] = b
        ans +=node.cost
print(result)
print(ans)