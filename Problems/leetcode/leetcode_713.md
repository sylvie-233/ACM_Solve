# 713. 乘积小于 K 的子数组

双指针
```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        product = 1
        left = 0
        res = 0
        for i, x in enumerate(nums):
            product *= x
            while product >= k and left <= i:
                product //= nums[left]
                left += 1
            if i >= left:
                res += i - left + 1
        return res
```