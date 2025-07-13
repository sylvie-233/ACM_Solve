# 3612. 用特殊操作处理字符串 I

简单字符串模拟


```python
class Solution:
    def processStr(self, s: str) -> str:
        res = ""
        for c in s:
            if c <= 'z' and c >= 'a':
                res += c
            elif c == '*':
                if len(res) > 0:
                    res = res[:-1]
            elif c == '#':
                res += res
            elif c == '%':
                res = res[::-1]
            # print(res)
        return res
```