# 2149. 按符号重排数组

简单构造

```python
class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        a = [i for i in nums if i > 0]
        b = [i for i in nums if i < 0]
        res = []
        for i in range(len(a)):
            res.append(a[i])
            res.append(b[i])
        return res
```