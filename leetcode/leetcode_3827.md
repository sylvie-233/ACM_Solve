# 3827. 统计单比特整数


枚举
```python
class Solution:
    def countMonobit(self, n: int) -> int:
        base = 2
        cnt = 0
        for i in range(0, n+1):
            if i == 0:
                cnt += 1
            elif i == base-1:
                cnt += 1
                base *= 2
        return cnt
```