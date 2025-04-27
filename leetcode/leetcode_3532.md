# 3532. 针对图的路径存在性查询 I

并查集

```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)

class Solution:
    def pathExistenceQueries(self, n: int, nums: list[int], maxDiff: int, queries: list[list[int]]) -> list[bool]:
        union_find = UnionFind(100005)
        p = 0
        for i in range(1, n):
            if nums[i] - nums[i - 1] <= maxDiff:
                union_find.union(i, i - 1)
        
        ans: list[bool] = []

        for i in queries:
            x, y = i
            if union_find.find(x) == union_find.find(y):
                ans.append(True)
            else:
                ans.append(False)
        
        return ans
```