# 2151. 基于陈述统计最多好人数


暴力枚举、位运算



```python
class Solution:
    def maximumGood(self, statements: list[list[int]]) -> int:
        n = len(statements)
        arr = [[0, 0] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                k = statements[i][j]
                if k == 0:
                    arr[i][1] = arr[i][1] | (1 << j)
                elif k == 1:
                    arr[i][0] = arr[i][0] | (1 << j)
        
        res = 0
        for i in range(1, 1 << n):
            c = 0
            for j in range(n):
                if i & (1 << j):
                    if (arr[j][0] & i == arr[j][0]) and (arr[j][1] & i == 0):
                        c = c + 1
                    else:
                        c = 0
                        break
            res = max(res, c)
        return res
```