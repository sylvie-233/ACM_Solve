# 100578. 中位数之和的最大值

简单模拟

```python
class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
        nums.sort()
        idx, n = 1, len(nums) // 3
        left, right = 0, len(nums) - 1
        res = 0
        while idx <= n:
            left += 1
            res += nums[right - 1]
            right -= 2
            idx += 1
        return res
```