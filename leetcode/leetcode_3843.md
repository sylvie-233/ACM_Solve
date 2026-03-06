# 3843. 频率唯一的第一个元素



```python
from collections import Counter

class Solution:
    def firstUniqueFreq(self, nums: list[int]) -> int:
        cnt1 = Counter()
        for i in nums:
            cnt1[i] += 1

        cnt2 = Counter()
        for k, v in cnt1.items():
            cnt2[v] += 1

        cnt3 = Counter()
        for k, v in cnt2.items():
            if v == 1:
                cnt3[k] += 1
        ans = -1
        for i in nums:
            if cnt1[i] in cnt3:
                ans = i
                break
        return ans
```