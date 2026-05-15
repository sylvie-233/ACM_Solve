# 3531. 统计被覆盖的建筑

简单搜索，四个方向

```python
from collections import defaultdict

class Solution:
    def countCoveredBuildings(self, n: int, buildings: list[list[int]]) -> int:
        d = defaultdict(int)
        t = [0] * 100005
        buildings.sort(key=lambda x: x[0])
        for i in buildings:
            x, y = i
            if t[y] > 0:
                d[x * 200000 + y] += 1
            t[y] += 1
        t = [0] * 100005
        buildings.sort(key=lambda x: -x[0])
        for i in buildings:
            x, y = i
            if t[y] > 0:
                d[x * 200000 + y] += 1
            t[y] += 1
        t = [0] * 100005
        buildings.sort(key=lambda x: x[1])
        for i in buildings:
            x, y = i
            if t[x] > 0:
                d[x * 200000 + y] += 1
            t[x] += 1
        t = [0] * 100005
        buildings.sort(key=lambda x: -x[1])
        for i in buildings:
            x, y = i
            if t[x] > 0:
                d[x * 200000 + y] += 1
            t[x] += 1
        res = 0
        for i in buildings:
            x, y = i
            if d[x * 200000 + y] == 4:
                res += 1

        return res
```