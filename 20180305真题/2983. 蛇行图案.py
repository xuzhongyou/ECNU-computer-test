"""
@Time:2018/3/6 16:40
@Author:xuzhongyou
"""

def inside(x1,y1):
    if x1>=1 and x1<=n and y1>=1 and y1<=n and (num[x1][y1]==0):
        return True
    return False



def cal(n):
    dx =[0,1,0,-1]
    dy =[1,0,-1,0]
    now = 0
    x, y = 1, 1
    dir = 0

    for i in range(n**2):
        now+=1
        num[x][y] =now
        #填充玩num下面就无需操作了，不然死循环
        if now==n**2:
            break
        x1 = x+dx[dir]
        y1 = y+dy[dir]
        # print(dx[dir],dy[dir],x1,y1)
        while(inside(x1,y1) is False):
            dir = (dir+1)%4
            x1 = x+dx[dir]
            y1 = y+dy[dir]
        x,y = x1,y1


if __name__ == '__main__':
    T =int(input())
    for _ in range(T):
        num = [[0 for i in range(11)] for i in range(11)]
        n = int(input())
        cal(n)
        print('case #%d:'%(_))
        for i in range(1,n+1):
            print(*num[i][1:n+1],sep=' ')