# 3613. 最小化连通分量的最大成本

最小生成树 + 贪心


```python
from typing import List

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n  # 用于优化合并树的深度

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # 路径压缩
        return self.parent[x]

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx == ry:
            return False  # 已经在同一个集合，加入会成环
        # 按秩合并
        if self.rank[rx] < self.rank[ry]:
            self.parent[rx] = ry
        elif self.rank[rx] > self.rank[ry]:
            self.parent[ry] = rx
        else:
            self.parent[ry] = rx
            self.rank[rx] += 1
        return True


def kruskal(n, edges):
    # edges: List of (u, v, w)
    edges.sort(key=lambda x: x[2])  # 按权重排序
    uf = UnionFind(n)
    mst = []
    total_weight = 0

    for u, v, w in edges:
        if uf.union(u, v):
            mst.append((u, v, w))
            total_weight += w
            if len(mst) == n - 1:
                break

    return total_weight, mst

class Solution:
    def minCost(self, n: int, edges: List[List[int]], k: int) -> int:
        _, mst_edges = kruskal(n, edges)
        if n == k: return 0
        mst_edges.sort(key=lambda x: -x[2])
        return mst_edges[k-1][2]
```