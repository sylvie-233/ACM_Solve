# 970. 强整数 


暴力枚举



```python
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> list[int]:
        if x > y:
            x, y = y, x
        res = []
        if y == 1:
            if 2 <= bound:
                res.append(2)
        elif x == 1:
            for i in range(21):
                if (1 + y ** i) <= bound:
                    res.append(1 + y ** i)
        else:
            for i in range(21):
                for j in range(21):
                    if (x ** i + y ** j) <= bound:
                        res.append(x ** i + y ** j)
        return list(set(res))
```