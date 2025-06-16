# 2150. 找出数组中的所有孤独数字


简单构造


```python
from collections import Counter

class Solution:
    def findLonely(self, nums: list[int]) -> list[int]:
        c = Counter(nums)
        res = []
        for i in nums:
            if (i + 1 not in c) and ( i - 1 not in c) and c[i] == 1:
                res.append(i)
        return res
        
```