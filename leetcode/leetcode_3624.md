# 3624. 位计数深度为 K 的整数数目 II

二维树状数组

```python
from typing import List
from functools import lru_cache

class MultiValueBIT:
    def __init__(self, data, max_val):
        """
        data: 初始数组，长度 n
        max_val: 值域最大值，假设值是 1..max_val
        """
        self.n = len(data)
        self.max_val = max_val
        # 为每个值建一个 BIT，BIT 下标从 1 开始
        self.BITs = [[0] * (self.n + 1) for _ in range(max_val + 1)]
        self.data = [0] + data  # 1-based 索引方便处理
        
        # 初始化 BIT
        for i in range(1, self.n + 1):
            val = self.data[i]
            self._update_BIT(val, i, 1)

    def _lowbit(self, x):
        return x & (-x)
    
    def _update_BIT(self, val, idx, delta):
        """
        单棵 BIT 更新 val 对应的树状数组：位置 idx 增加 delta
        """
        while idx <= self.n:
            self.BITs[val][idx] += delta
            idx += self._lowbit(idx)
    
    def _query_BIT(self, val, idx):
        """
        查询 val 对应的树状数组前缀和：[1..idx]
        """
        res = 0
        while idx > 0:
            res += self.BITs[val][idx]
            idx -= self._lowbit(idx)
        return res
    
    def update(self, pos, new_val):
        """
        更新位置 pos 的值为 new_val
        """
        old_val = self.data[pos]
        if old_val == new_val:
            return
        # 先在 old_val 的 BIT 中减去 1
        self._update_BIT(old_val, pos, -1)
        # 在 new_val 的 BIT 中加上 1
        self._update_BIT(new_val, pos, 1)
        # 更新数组记录
        self.data[pos] = new_val
    
    def query(self, val, left, right):
        """
        查询值为 val 的元素在区间 [left, right] 出现次数
        """
        return self._query_BIT(val, right) - self._query_BIT(val, left - 1)


class Solution:
    def popcountDepth(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        @lru_cache
        def popcount_depth(x: int) -> int:
            if x == 1:
                return 0
            return 1 + popcount_depth(bin(x).count('1'))
        # print(popcount_depth(2))

        nums_pop = [popcount_depth(i) for i in nums]
        bit = MultiValueBIT(nums_pop, 10) 
        res = []
        for q in queries:
            if q[0] == 1:
                l, r, k = q[1] + 1, q[2] + 1, q[3]
                res.append(bit.query(k, l, r))
            else:
                idx, val = q[1] + 1, q[2]
                bit.update(idx, popcount_depth(val))
        return res
```