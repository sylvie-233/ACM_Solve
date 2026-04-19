# smallest-stable-index-ii


简单计算，前后缀计算
```python
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        arr_max = []
        v = nums[0]
        for i in range(n):
            v = max(nums[i], v)
            arr_max.append(v)

        arr_min = []
        v = nums[-1]
        for i in range(n-1, -1, -1):
            v = min(nums[i], v)
            arr_min.append(v)

        for i in range(n):
            v = arr_max[i] - arr_min[n-1-i]
            if v <= k:
                return i

        return -1
```