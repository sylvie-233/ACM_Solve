# 2444. 统计定界子数组的数目

简单搜索、计数



```python
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        p_mink = -1
        p_maxk = -1
        p_left = 0
        for i, v in enumerate(nums):
            p = i + 1
            if v >= minK and v <= maxK:
                if v == minK:
                    p_mink = p
                if v == maxK:
                    p_maxk = p
                if p_mink != -1 and p_maxk != -1:
                    res += min(p_maxk, p_mink) - p_left
            else:
                p_left = p
                p_maxk = -1
                p_mink = -1
        return res
        
```