"""
@Time:2018/1/9 15:28
@Author:xuzhongyou
"""
class Node:
    def __init__(self,value=None,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right


def pre_order(root):
    print(root.value)
    if root.left is not None:
        pre_order(root.left)
    if root.right is not None:
        pre_order(root.right)

if __name__ == '__main__':
    root = Node('D',Node('B',Node('A'),Node('C')),Node('E',right=Node('G',Node('F'))))
    pre_order(root)
