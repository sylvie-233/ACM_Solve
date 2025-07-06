# 3607. 电网维护 

简单并查集


```python
from collections import deque

class UnionFind:
    def __init__(self, n: int):
        # 初始化并查集，每个元素的父节点是它自己
        self.parent = list(range(n))
    
    def find(self, x: int) -> int:
        # 查找元素 x 的根节点，并进行路径压缩
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # 递归查找并路径压缩
        return self.parent[x]
    
    def union(self, x: int, y: int) -> None:
        # 合并元素 x 和 y
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX != rootY:
            self.parent[rootX] = rootY  # 将 x 的根节点指向 y 的根节点

    def connected(self, x: int, y: int) -> bool:
        # 判断 x 和 y 是否属于同一个集合
        return self.find(x) == self.find(y)

class Solution:
    def processQueries(self, c: int, connections: list[list[int]], queries: list[list[int]]) -> list[int]:
        uf = UnionFind(c + 1)
        uf_queue = [deque() for i in range(c + 1)]
        uf_inline = [True for _ in range(c + 1)]
        for i in connections:
            uf.union(i[0], i[1])
        for i in range(1, c + 1):
            p = uf.find(i)
            uf_queue[p].append(i)
        res = []
        for i in queries:
            f, x = i
            if f == 1:
                if uf_inline[x]:
                    res.append(x)
                else:
                    p = uf.find(x)
                    while uf_queue[p] and (not uf_inline[uf_queue[p][0]]):
                        uf_queue[p].popleft()
                    if uf_queue[p]:
                        res.append(uf_queue[p][0])
                    else:
                        res.append(-1)    
            else:
                uf_inline[x] = False
        return res
```