# 1604. 警告一小时内使用相同员工卡大于等于三次


简答构造，字符串转数字


```python
from collections import defaultdict

class Solution:

    def alertNames(self, keyName: list[str], keyTime: list[str]) -> list[str]:
        d = defaultdict(list[str])
        n = len(keyName)
        for i in range(n):
            d[keyName[i]].append(keyTime[i])
        res: list[str] = []
        for k, v in d.items():
            v.sort()
            n_v = len(v)
            v_c = list(map(lambda x: (int(x[0:2]) * 60 + int(x[3:5])), v))
            # print(v_c)
            if n_v >= 3:
                for i in range(1, n_v - 1):
                    if v_c[i + 1] - v_c[i - 1] <= 60:
                        res.append(k)
                        break
        res.sort()
        return res
```