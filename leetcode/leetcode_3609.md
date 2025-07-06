# 3609. 到达目标点的最小移动次数

数学分析

```python
class Solution:
    def minMoves(self, sx: int, sy: int, tx: int, ty: int) -> int:
        steps = 0
        if sx == tx and sy == ty:
            return 0
        if sx == 0 and sy == 0:
            return -1
        while tx >= sx and ty >= sy:
            if tx == sx and ty == sy:
                return steps
            if tx > ty:
                if tx > 2 * ty:
                    tx = tx / 2
                else:
                    tx -= ty
            elif tx < ty:
                if ty > tx * 2:
                    ty = ty / 2
                else:
                    ty -= tx
            else:
                if (sx != 0 and sy != 0) or (sx == 0 and sy == 0):
                    return -1
                mx = max(sx, sy)
                if tx % mx == 0:
                    tx = tx / mx
                    steps = steps + 1
                    while tx % 2 == 0:
                        tx = tx / 2
                        steps = steps + 1
                    if tx == 1:
                        return steps
                    else:
                        return -1
                else:
                    return -1
                
            steps = steps + 1
        return -1
```