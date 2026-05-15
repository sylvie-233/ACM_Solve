# 3599. 划分数组得到最小 XOR

区间DP

```python
class Solution:
    def minXor(self, nums: List[int], k: int) -> int:
        n = len(nums)
        INF = float("inf")

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] ^ nums[i]
        
        # dp[1~n][1~k]
        dp = [[INF] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        # 分t段
        for t in range(1, k + 1):
            # 枚举端点（分t段，则端点最小为t）
            for i in range(t, n + 1):
                # 枚举分隔点（上次t-1段）
                for j in range(t - 1, i):
                    dp[i][t] = min(dp[i][t], max(dp[j][t - 1], prefix[i] ^ prefix[j]))
        return dp[n][k]
```