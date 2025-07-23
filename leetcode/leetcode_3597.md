# 3597. 分割字符串

简单字符串

```python
class Solution:
    def partitionString(self, s: str) -> List[str]:
        d = defaultdict(int)
        res = []
        res.append(s[0:1])
        d[s[0:1]] += 1
        pre = 1
        for i in range(1,len(s)):
            if s[pre:i+1] in d:
                continue
            else:
                res.append(s[pre:i+1])
                d[s[pre:i+1]] += 1
                pre = i + 1
        return res
```