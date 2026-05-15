# 3608. 包含 K 个连通分量需要的最小时间 

二分 + 并查集


```python
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

    def count_components(self):
        return len(set(self.find(i) for i in range(len(self.parent))))

class Solution:

    @staticmethod
    def check(time: int, n: int, edges: list[list[int]], k: int) -> bool:
        uf = UnionFind(n)
        for i in edges:
            u, v, t = i
            if t <= time:
                continue
            uf.union(u, v)
        return uf.count_components() >= k

    def minTime(self, n: int, edges: list[list[int]], k: int) -> int:
        if Solution.check(0, n, edges, k):
            return 0
        times = []
        for i in edges:
            times.append(i[2])
        times = sorted(set(times))
        left, right = 0, len(times) - 1
        ans = max(times)
        while left <= right:
            mid = (left + right) // 2
            if Solution.check(times[mid], n, edges, k):
                ans = times[mid]
                right = mid - 1  # 继续向左找更小的
            else:
                left = mid + 1
        return ans
```