"""
@Time:2018/2/23 14:48
@Author:xuzhongyou
"""
#一行x,y,z
#x表示oxx直接回家所需的时间
#y表示xjj到家所需的时间
#z表示到先到xjj家再到oxx家的时间
# input
# 2 2 4
# output
# 1.00

#a,b,c  a表示到达终点站,b表示终点站达到xjj，c表示终点站到达oxx
#a+b =x
#a+c = y
#x+b+c = z  求a   2x+y-z  / 2 = a

def process(nums):
    x = int(nums[0])
    y = int(nums[1])
    z = int(nums[2])
    result= (2*y+x-z) / 2
    if result<=0 or z<=x or z<=y or result>=x or result>=y or  result>=z:
        print('Wrong')
    else:
        print('%.2f'%(result))
if __name__ == '__main__':
    inputs = input().split(' ')
    process(inputs)
