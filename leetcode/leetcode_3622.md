# 3622. 判断整除性

简单运算

```python
class Solution:
    def checkDivisibility(self, n: int) -> bool:
        num_arr = list(map(int, str(n)))
        num_sum = sum(num_arr)
        num_star = 1
        for i in num_arr:
            num_star *= i
        # print(num_arr)
        # print(num_sum, num_star)
        return n % (num_sum + num_star) == 0
```