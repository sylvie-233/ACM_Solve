# 209. 长度最小的子数组

双指针

```python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        res = n + 1
        s = 0
        for i, x in enumerate(nums):
            s += x
            while s >= target:
                res = min(res, i - left + 1)
                s -= nums[left]
                left += 1
        return res if res <= n else 0
```