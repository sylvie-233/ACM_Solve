# 100985. 统计主导元素下标数


枚举
```python
class Solution:
    def dominantIndices(self, nums: list[int]) -> int:
        sums = nums[-1]
        avg = nums[-1]
        n = len(nums)
        cnt = 0
        for i in range(n - 2, -1, -1):
            if nums[i] > avg:
                cnt += 1
            sums += nums[i]
            avg = sums / (n - i)
        return cnt
```