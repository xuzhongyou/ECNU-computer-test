"""
@Time:2018/1/11 14:19
@Author:xuzhongyou
"""
#要求：一系列整数，建立二叉排序树，并进行前序，中序，后序遍历
#输入：1 6 5 9 8
#输出：1 6 5 9 8
#  ：1 5 6 8 9
#  ：5 8 9 6 1
str_ = '1 6 5 9 8'
str_list= list(str_.split(' '))
result = []
class Node:
    def __init__(self,value=None,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right


def after_order(root):
    if root.left is not None:
        after_order(root.left)
    if root.right is not None:
        after_order(root.right)
    result.append(root.value)

def pre_order(root):
    result.append(root.value)
    if root.left is not None:
        pre_order(root.left)
    if root.right is not None:
        pre_order(root.right)

def mid_order(root):
    if root.left is not None:
        mid_order(root.left)
    result.append(root.value)
    if root.right is not None:
        mid_order(root.right)

#递归好好思考
def BST(root,value):
    if root is None:
        root =Node(value)
    elif root.value>value:
        root.left = BST(root.left,value)
    elif root.value<value:
        root.right = BST(root.right,value)
    return root

root = None
for value in str_list:
    root = BST(root,value)

# print(root.right.value)
# pre_order(root)
mid_order(root)
# after_order(root)
#不存在会多一个空格的情况
print(" ".join(result))