# 3828. 删除子数组后的最终元素


结论
```python
class Solution:
    def finalElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(nums[0], nums[-1])
```