"""
@Time:2018/1/25 15:00
@Author:xuzhongyou
"""
#畅通工程的目标是使全省任何两个城镇间都可以实现交通，
# 但不一定有直接的道路连接，只要相互间接通过道路可达即可。
#输入：第一行给出两个正整数，分别是城镇数目N，道路数目M。
#随后M行对应着M条道路，每行给出一对正整数，分别连接两个城镇的编号
#输出：一行里输出至少还需要建设的道路数目
#思路：抽象成在一个图上查找连通分量的个数。


#并查集记得应用
n = 999
m = 0
result = [-1]*(n+1)
def findRoot(i):
    if result[i]== -1: return  i
    else:
        return findRoot(result[i])
#这边有一个特殊情况，当m为0的时候，直接给出结果，而不需要进入循环
for i in range(m):
    inputs = input().split(' ')
    index1 = int(inputs[0])
    index2 = int(inputs[1])
    a = findRoot(index1)
    b = findRoot(index2)
    if a != b:
        result[index1] = index2
print(result.count(-1)-2)