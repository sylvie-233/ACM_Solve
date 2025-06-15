# 100682. 统计特殊三元组

二分查找区间个数


```python
import bisect
from collections import defaultdict

class Solution:
    def specialTriplets(self, nums: list[int]) -> int:
        # 1. 构建每个值 -> 它出现的下标列表
        pos_map = defaultdict(list)
        for i, num in enumerate(nums):
            pos_map[num].append(i)

        mod = 10**9 + 7
        res = 0

        for i, x in enumerate(nums):
            x2 = x * 2
            if x2 in pos_map:
                idx_list = pos_map[x2]
                # 2. 使用二分查找在下标列表中快速查 i 的位置
                less = bisect.bisect_left(idx_list, i)
                greater = len(idx_list) - bisect.bisect_right(idx_list, i)
                # 3. 累加满足条件的三元组数量
                res = (res + less * greater) % mod

        return res
```