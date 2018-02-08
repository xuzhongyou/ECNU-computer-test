"""
@Time:2018/1/10 16:20
@Author:xuzhongyou
"""
#给定一棵二叉树的前序遍历和中序遍历，求其后序遍历
#输入：第一行为前序遍历，第二行为中序遍历，名称以大写字母表示
#输出：后序遍历的字符串

#递归很重要

class Node:
    def __init__(self,value=None,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right

str_1 = 'FDXEAG'
pre = list(str_1)
str_2 = 'XDEFAG'
mid =list(str_2)

result = []
def after_order(root):
    if root.left is not None:
        after_order(root.left)
    if root.right is not None:
        after_order(root.right)
    result.append(root.value)


def get_root(pre,mid):
    if len(pre) == 0 :
        return None
    if len(pre) == 1 :
        return Node(pre[0])
    root = Node(pre[0])
    root_index = mid.index(pre[0])
    root.left = get_root(pre[1:root_index+1],mid[:root_index])
    root.right = get_root(pre[root_index+1:],mid[root_index+1:])
    return root

root = get_root(str_1,str_2)
after_order(root)
print("".join(result))