"""
@Time:2018/1/30 9:44
@Author:xuzhongyou
"""
#大意为：平面上有若干个点，我们需要用一些线段将这些点连接起来使任意两个点通过一系列的线段相联
#求一种连接方式使所有线段的长度和最小，求该长度和
#注意，题目给的是点的坐标，当然需要转化为图上的结点。边，有权值
#注意一个套路，最小生成树的问题，最好用类来解决。

#其实并不需要纠结坐标的问题，这是有点变扭
class edge:
    def __init__(self,a,b,cost):
        self.a = a
        self.b = b
        self.cost = cost

class node:
    def __init__(self,x,y):
        self.x = x
        self.y = y

def cal_cost(node1,node2):
    return ((node1.x-node2.x)**2+(node1.y-node2.y)**2)**(0.5)

node_list = list()
edj_list = []
n = int(input())
#node_list从零开始
for i in range(n):
    inputs = input().split(" ")
    num1 = float(inputs[0])
    num2 = float(inputs[1])
    node_list.append(node(num1,num2))
#计算权重n(n-1)/2次
for i in range(n):
    for j in range(i+1,n):
        cost = cal_cost(node_list[i],node_list[j])
        edj_list.append(edge(i,j,cost))
#并查集
def findroot(x):
    if flag[x] == -1:return x
    else:
        temp = findroot(flag[x])
        flag[x] = temp
        return temp

#sorted完之后要赋值
edj_list = sorted(edj_list,key=lambda edj:edj.cost)
m = 100
#flag并不影响结果
flag = [-1]*m
ans = 0
for edj in edj_list:
    a = findroot(edj.a)
    b = findroot(edj.b)
    if a!=b :
        flag[a] = b
        ans += edj.cost
print('%.2f'%ans)








