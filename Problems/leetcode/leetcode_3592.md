# 3592. 硬币面值还原

完全背包计数


```python
class Solution:
    def findCoins(self, numWays: List[int]) -> List[int]:
        numWays = [0] + numWays
        n = len(numWays)
        res = []
        dp = [0] * n
        dp[0] = 1
        # print(list(range(n)))
        # print(numWays)
        # print("-------------------------------------------")
        while True:
            # 全为0，则结束
            if all(numWays[i] == dp[i] for i in range(1, n)):
                return res

            # 找1
            flag = False
            for i in range(1, n):
                if numWays[i] - dp[i] == 1:
                    flag = True
                    res.append(i)
                    break
            
            dp = [0] * n
            dp[0] = 1
            # 完全背包
            for j in res:
                for i in range(j, n):
                        dp[i] += dp[i - j]
            # print(res)
            # print(list(range(n)))
            # print(dp)
            # print("-------------------------------------------")

            # 没有1
            if not flag:
                return []
```