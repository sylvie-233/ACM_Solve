# 3638. 平衡装运的最大数量

贪心


```python
class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        res = 0
        n = len(weight)
        i = n - 1
        while i >= 0:
            if i - 1 >= 0:
                if weight[i - 1] > weight[i]:
                    # print(i)
                    res += 1
                    i -= 2
                    continue
            i -= 1
        return res
```