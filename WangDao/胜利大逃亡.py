"""
@Time:2018/2/7 11:11
@Author:xuzhongyou
"""
#这个一个广度优先搜索
#Ignatius被关在（0,0,0）的位置，门在（A-1,B-1,C-1)的位置，魔王T分钟内回到城堡，每分钟从一个坐标走到相邻的A个B*C的矩阵
#六个坐标中的一个，求能离开的最少需要的时间。
#输入第一行是四个正整数A,B,C,T分别代表城堡的大小和魔王回来的时间
#设定状态四元组（x,y,z,t）表示（0,0,0）到（x,y,z）的耗费时间
#所谓广度优先搜索，即在遍历解答树时使每次状态转移时扩展出尽可能多的新的状态
#并且按照各个状态的先后顺序依次扩展他们。理解为深度为1，深度为2，第一次访问到状态坐标即为最短时间。
#优化，通过剪枝来减少查找的状态总数。


#用元组来保存每一个状态
#(x,y,z,t) ,同时为了顺序转移的扩展，需要使用一个队列

#为了防止对无效状态的搜索，需要一个标记数组，包含之后置为True
#道路的可同性，还需要一个存储道路的数组

#输入
# 3 3 4 20
# 0 1 1 1
# 0 0 1 1
# 0 1 1 1
# 1 1 1 1
# 1 0 0 1
# 0 1 1 1
# 0 0 0 0
# 0 1 1 0
# 0 1 1 0
#输出 11
import queue

#数组的初始化
n = 5
m = 5
k = 5
maze = [None]*n
mark = [None]*n
for i in range(n):
    maze[i] = [0]*m
    mark[i] = [0]*m
for i in range(n):
    for j in range(m):
        maze[i][j] = [0]*k
        mark[i][j] = [0]*k

#输入maze矩阵
inputs = input().split(" ")
a = int(inputs[0])
b = int(inputs[1])
c = int(inputs[2])
for i in range(a):
    for j in range(b):
        info = input().split(' ')
        for k,content in enumerate(info):
            maze[i][j][k] = content
#没问题
result_list = []
print(maze)
#广度优先搜索
#方向控制list
dir_list = [(1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1)]
q = queue.Queue()
def BFS(a,b,c):#初始状态abc
    while q.empty() is False:
        now = q.get()
        for i in range(6):
            nx = now[0]+dir_list[i][0]
            ny = now[1]+dir_list[i][1]
            nz = now[2]+dir_list[i][2]
            if nx<0 or nx>=a or ny<0 or ny>=b or nz<0 or nz>=c:continue
            if maze[nx][ny][nz] ==1:continue
            if mark[nx][ny][nz] ==1:continue
            temp = (nx,ny,nz,now[3]+1)
            result_list.append(temp)
            q.put(temp)
            mark[nx][ny][nz] = 1
            if nx == a-1 and ny == b-1 and nz == c-1:
                print('nx,ny,nz',nx,ny,nz)
                return temp[3]
    return -1

if __name__ == '__main__':
    q = queue.Queue()
    while q.empty() is False :q.get()
    mark[0][0][0] = 1 #标记起点
    now = (0,0,0,0)
    q.put(now)
    print("abc ",a,'-',b,'-',c)
    result = BFS(a,b,c)
    print(result)
    print(result_list)




