# 3623. 统计梯形的数目 I

简单组合数学 + 优化

```python
from typing import List
from collections import Counter

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        d = Counter([p[1] for p in points])
        # print(d)
        mod = int(10 ** 9 + 7)
        l_c = [i * (i - 1) // 2 for i in d.values() if i != 0]
        # print(l_c)
        res = 0
        total = sum(l_c) % mod
        for i in l_c:
            total = (total - i + mod) % mod
            res = (res + total * i % mod) % mod
        return res
```