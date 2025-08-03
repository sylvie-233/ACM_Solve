# 3637. 三段式数组 I


简单数组


```python
class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        def check(l: int, r: int, isAsc: bool) -> bool:
            for i in range(l, r):
                if isAsc:
                    if nums[i] >= nums[i + 1]:
                        return False
                else:
                    if nums[i] <= nums[i + 1]:
                        return False
            return True

        n = len(nums)
        for p in range(1, n - 1):
            for q in range(p + 1, n - 1):
                if check(0, p, True) and check(p, q, False) and check(q, n - 1, True):
                    # print(p, q)
                    return True
        return False
```