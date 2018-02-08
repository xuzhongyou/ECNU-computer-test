"""
@Time:2018/2/7 11:57
@Author:xuzhongyou
"""
#方法一创建二维数组
n = 2
m = 3
matrix = [None]*2

for i in range(len(matrix)):
    matrix[i] = [0]*3
print(matrix)
matrix[0][0] = 1
print(matrix)

print('-------------------------------')

#第二种创建二维数组
n = 2
m = 3
matrix = [[0]*m for i in range(n)]
print(matrix)
matrix[0][0] = 1
print(matrix)

print('-------------------------------------')

#第三种创建多维数组
n = 2
m = 3
k = 4
#想象两个3*4的数组
matrix = [None] * 2
for i in range(len(matrix)):
    matrix[i] = [0] * 3
print(matrix)
for i in range(n):
    for j in range(m):
        matrix[i][j] = [1] * k
matrix[0][0][0] = 0
print(matrix)
#方法三
#这种方法是不可取的
# result = [[0]*2]*3
# print(result)
# result[0][0] = 1
# print(result)

