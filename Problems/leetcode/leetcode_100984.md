# 100984. 合并相邻且相等的元素


模拟
```python
class Solution:
    def mergeAdjacent(self, nums: list[int]) -> list[int]:
        ans = []
        for i in nums:
            ans.append(i)
            while len(ans) > 1 and ans[-1] == ans[-2]:
                t = ans[-1] * 2
                ans.pop()
                ans.pop()
                ans.append(t)

        return ans
```