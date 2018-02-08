"""
@Time:2018/2/2 13:44
@Author:xuzhongyou
"""
#百鸡问题：
#用小于等于n元去买100只鸡，大鸡5/只，小鸡3/只，还有1/3元每只，分别记为x只，y只，z只，变成求解x,y,z的所有可能解
n = 1000
result = []
import datetime
import time
# start_time = datetime.datetime.now()
start_time = time.time()
print(start_time)
for i in range(int(n/5)+1):
    for j in range(int(n/3)+1):
        #这边可以优化，少一层循环
        for k in range(301):
            if 5*i+j*3+(1/3)*k <= n and i+j+k ==100:
                result.append((i,j,k))
# end_time = datetime.datetime.now()
end_time = time.time()
print(end_time)
print("time is",(end_time-start_time))
print(len(result))
# print(result)