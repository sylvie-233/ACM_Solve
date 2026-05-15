# 1380. 矩阵中的幸运数

简单遍历

```python
class Solution:
    def luckyNumbers(self, matrix: list[list[int]]) -> list[int]:
        n = len(matrix)
        m = len(matrix[0])

        row_max = [[False] * m for _ in range(n)]
        # print(row_max)
        for i in range(n):
            p = 0
            for j in range(m):
                if matrix[i][j] < matrix[i][p]:
                    p = j
            for j in range(m):
                if matrix[i][j] == matrix[i][p]:
                    row_max[i][j] = True

        res: list[int] = []
        for j in range(m):
            p = 0
            for i in range(n):
                if matrix[i][j] > matrix[p][j]:
                    p = i
            if row_max[p][j]:
                res.append(matrix[p][j])

        return res
```