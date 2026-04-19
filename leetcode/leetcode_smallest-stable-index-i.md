# smallest-stable-index-i


简单计算
```python
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        ans = -1
        ans_p = -1
        for i in range(n):
            v = max(nums[:i+1]) - min(nums[i:n]) 
            if v <= k:
                ans = v
                ans_p = i
                break
        return ans_p
```