# 84. 柱状图中最大的矩形

单调栈（左右遍历两次）

```python
from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        res_left = [i for i in range(n)]
        for i, x in enumerate(heights):
            while stack and heights[stack[-1]] >= x:
                idx = stack.pop()
                res_left[i] = res_left[idx]
            stack.append(i)
        
        # 清空单调栈
        stack.clear()
    
        res_right = [i for i in range(n)]
        for i, x in enumerate(heights[::-1]):
            while stack and heights[stack[-1]] >= x:
                idx = stack.pop()
                res_right[n - 1 - i] = res_right[idx]
            stack.append(n - 1 - i) 
        # print(res_left)
        # print(res_right)
        return max([(res_right[i] - res_left[i] + 1) * heights[i] for i in range(n)])
```