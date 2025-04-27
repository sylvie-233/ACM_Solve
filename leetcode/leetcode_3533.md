# 3533. 判断连接可整除性

状压DP，记忆化搜索全排列

```python
from functools import cache

class Solution:
    def concatenatedDivisibility(self, nums: list[int], k: int) -> list[int]:
        nums.sort()
        n = len(nums)
        ans = []

        @cache
        def zy_dp(s: int, rem: int) -> bool:
            if s == 0:
                return rem == 0
            
            for i in range(n):
                if s & (1 << i) and zy_dp(s ^ (1 << i), (rem * (10 ** len(str(nums[i]))) + nums[i]) % k):
                    ans.append(nums[i])
                    return True
            return False

        if not zy_dp((1 << n) - 1, 0):
            return []
        ans.reverse()
        return ans
```