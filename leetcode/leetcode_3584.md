# 3584. 子序列首尾元素的最大乘积


ST表区间最值查询


```python
from collections import deque

import math

class SparseTable:
    def __init__(self, nums):
        self.n = len(nums)
        self.k = int(math.log2(self.n)) + 1
        self.nums = nums
        self.st_max = [[0] * self.k for _ in range(self.n)]
        self.st_min = [[0] * self.k for _ in range(self.n)]

        # 初始化
        for i in range(self.n):
            self.st_max[i][0] = nums[i]
            self.st_min[i][0] = nums[i]

        # 构建 ST 表
        for j in range(1, self.k):
            for i in range(self.n - (1 << j) + 1):
                self.st_max[i][j] = max(self.st_max[i][j - 1], self.st_max[i + (1 << (j - 1))][j - 1])
                self.st_min[i][j] = min(self.st_min[i][j - 1], self.st_min[i + (1 << (j - 1))][j - 1])

    def query_max(self, l, r):
        """查询区间 [l, r] 内最大值"""
        j = int(math.log2(r - l + 1))
        return max(self.st_max[l][j], self.st_max[r - (1 << j) + 1][j])

    def query_min(self, l, r):
        """查询区间 [l, r] 内最小值"""
        j = int(math.log2(r - l + 1))
        return min(self.st_min[l][j], self.st_min[r - (1 << j) + 1][j])

class Solution:
    def maximumProduct(self, nums: list[int], m: int) -> int:
        if m == 1:
            res = nums[0] * nums[-1]
            for i in nums:
                res = max(res, i * i)
            return res
        else:
            res = nums[0] * nums[-1]
            k = m - 1
            st = SparseTable(nums)
            for i in range(len(nums)):
                x = nums[i]
                if i >= k:
                    q_max = st.query_max(0, i - k)
                    q_min = st.query_min(0, i - k)
                    res = max(res, x * q_max)
                    res = max(res, x * q_min)
            return res
        
```