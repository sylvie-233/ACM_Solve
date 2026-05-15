# 2441. 与对应负数同时存在的最大正整数

简单遍历

```python
from collections import Counter

class Solution:
    def findMaxK(self, nums: list[int]) -> int:
        d = Counter(nums)
        ans = -1
        for i in nums:
            if d[-i] != 0:
                ans = max(ans, i)
        return ans
```