# 100688. 为视频标题生成标签


简单字符串构造


```python
class Solution:
    def generateTag(self, caption: str) -> str:
        s = caption.split(" ")
        s = [i for i in s if i != ""]
        if len(s) > 1:
            for i in range(1, len(s)):
                s[i] = s[i].capitalize()
        if len(s) == 0:
            return "#"
        s[0] = s[0].lower()
        s = "#" + "".join(s)
        return s[0:100]
```