# 3640. 三段式数组 II

线性DP：状态转移（三段）

```python
class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        res = MIN_VALUE = -1e18
        dp = [[MIN_VALUE] * 3 for _ in range(n + 5)]
        dp[0][0] = nums[0]
        for i in range(1, n):
            dp[i][0] = nums[i]
            if nums[i] > nums[i - 1]:
                # 第1段延续
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + nums[i])
                # 第2段起头
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + nums[i])

                # 第3段延续
                if dp[i - 1][2] != MIN_VALUE:
                    dp[i][2] = max(dp[i][2], dp[i - 1][2] + nums[i])
                    res = max(res, dp[i][2])
            if nums[i] < nums[i - 1]:
                # 第2段延续
                if dp[i - 1][1] != MIN_VALUE:
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + nums[i])
                    dp[i][2] = max(dp[i][2], dp[i - 1][1] + nums[i])
        return res
```