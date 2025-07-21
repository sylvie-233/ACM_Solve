# 34. 在排序数组中查找元素的第一个和最后一个位置

二分查找
```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # lower_bound
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        if not (left >= 0 and left <= len(nums) - 1 and nums[left] == target):
            return [-1, -1]
        l = left

        # upper_bound
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return [l, left - 1]
```