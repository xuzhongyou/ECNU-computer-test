"""
@Time:2018/1/9 14:15
@Author:xuzhongyou
"""
#第一行输入一个数n，表示叶节点的个数。需要用这些叶节点生成哈夫曼树
#输出所有节点的值与权值的乘积之和

#样例输入
#5
#1 2 2 5 9
#样例输出
#37

#有两种方法，第一种构造一棵完整的哈夫曼树
# 第二种非叶子结点的值的和。
#思想：
#不停的排序取前两个值

str_ = '1 2 2 5 9'
num_str = [int(i) for i in str_.split(" ")]
sorted_num = sorted(num_str)
result = []
while(len(sorted_num)>1):
    temp = sorted_num[0] + sorted_num[1]
    #注意这边删掉的索引都是 0
    del sorted_num[0]
    del sorted_num[0]
    result.append(temp)
    sorted_num.append(temp)
    sorted_num = sorted(sorted_num)
print(sum(result))





