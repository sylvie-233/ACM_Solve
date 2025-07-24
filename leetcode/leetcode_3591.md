# 3591. 检查元素频次是否为质数

简单模拟

```python
class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        def is_prime(num: int) -> bool:
            if num == 1:
                return False
            else:
                for i in range(2, num):
                    if num % i == 0:
                        return False
                return True
        d = Counter(nums)
        return any([is_prime(d[i]) for i in nums])
```