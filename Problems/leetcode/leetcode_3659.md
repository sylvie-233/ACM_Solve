# 3659. 数组元素分组

简单逻辑判断

```python
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> bool:
        d = defaultdict(int)
        n = len(nums)
        if n % k != 0:
            return False
        c = n // k
        for v in nums:
            d[v] += 1
        max_cnt = 0
        for _, v in d.items():
            max_cnt = max(max_cnt, v)
        if max_cnt > c:
            return False
        return True
```