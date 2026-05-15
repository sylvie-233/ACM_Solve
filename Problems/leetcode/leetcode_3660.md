# 3660. 跳跃游戏 9

复杂逻辑判断

```python
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # 左边最大值
        left_max = [0] * n
        left_max[0] = nums[0]
        for i in range(1, n):
            left_max[i] = max(nums[i], left_max[i - 1])

        # 右边最小值
        right_min = [0] * n
        right_min[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            right_min[i] = min(nums[i], right_min[i + 1])
        
        res = [0] * n
        res[n - 1] = max_num = left_max[n - 1]
        for i in range(n - 2, -1, -1):
            # 左边最大值 <= 右边最小值，说明区间断开，重新获取最大值
            if left_max[i] <= right_min[i + 1]:
                max_num = left_max[i]
            res[i] = max_num

        return res
```