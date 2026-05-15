# 167. 两数之和 II - 输入有序数组


双指针
```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        numbers.sort()
        left = 0
        right = len(numbers) - 1
        while left < right:
            num_sum = numbers[left] + numbers[right]
            if num_sum == target:
                break
            elif num_sum > target:
                right -= 1
            else:
                left += 1
        return [left + 1, right + 1]
```