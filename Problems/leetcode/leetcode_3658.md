# 3658. 奇数和与偶数和的最大公约数

简单数学计算

```python
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd = n ** 2
        sumEven = n * (n + 1)
        return gcd(sumOdd, sumEven)
```