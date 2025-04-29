# 1605. 给定行和列的和求可行矩阵

简单构造、贪心

```python
class Solution:
    def restoreMatrix(self, rowSum: list[int], colSum: list[int]) -> list[list[int]]:
        n = len(rowSum)
        m = len(colSum)
        g = [[0] * m for _ in range(n)]
        # print(g)
        for i in range(n):
            for j in range(m):
                if colSum[j] > 0:
                    if rowSum[i] > colSum[j]:
                        g[i][j] = colSum[j]
                        rowSum[i] -= colSum[j]
                        colSum[j] = 0
                    elif rowSum[i] == colSum[j]:
                        g[i][j] = rowSum[i]
                        rowSum[i] = 0
                        colSum[j] = 0
                        break
                    else:
                        g[i][j] = rowSum[i]
                        colSum[j] -= rowSum[i]
                        rowSum[i] = 0
                        break
        return g
```