# 2443. 反转之后的数字和

简单遍历

```python
class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        res = False
        for i in range(num + 1):
            i_rev = int(str(i)[::-1])
            if  i + i_rev == num:
                res = True
                break
        return res      
```