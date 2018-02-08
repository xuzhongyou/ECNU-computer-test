"""
@Time:2018/2/7 13:58
@Author:xuzhongyou
"""
import queue
q = queue.Queue()
print(q.empty())
q.put('a')
q.put('b')
print(q.get())
print(q.empty())
print(q.get())
print(q.empty())
