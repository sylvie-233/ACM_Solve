# 2442. 反转之后不同整数的数目

简单构造计数

```python
from collections import Counter

class Solution:
    def countDistinctIntegers(self, nums: list[int]) -> int:
        t = nums[:]
        for i in nums:
            t.append(int(str(i)[::-1]))
        cnt = Counter(t)
        return len(cnt)
```