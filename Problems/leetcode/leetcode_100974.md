# 100974. 恰好 K 个下标对的最大得分


序列dp
```python
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[[-inf]*(k+1) for _ in range(m+1)] for __ in range(n+1)]

        for i in range(n+1):
            for j in range(m+1):
                dp[i][j][0] = 0

        for i in range(1, n+1):
            for j in range(1, m+1):
                for t in range(0, k+1):

                    dp[i][j][t] = max(
                        dp[i-1][j][t],
                        dp[i][j-1][t]
                    )

                    if t > 0 and dp[i-1][j-1][t-1] != -inf:
                        dp[i][j][t] = max(
                            dp[i][j][t],
                            dp[i-1][j-1][t-1] +
                            nums1[i-1]*nums2[j-1]
                        )

        return dp[n][m][k]
```