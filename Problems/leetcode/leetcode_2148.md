# 2148. 元素计数

简单构造

```python
from collections import Counter

class Solution:
    def countElements(self, nums: list[int]) -> int:
        c = Counter(nums)
        mx = max(nums)
        mn = min(nums)
        res = len(nums) - c[mx]
        if mx != mn:
            res = res - c[mn]
        return res
```