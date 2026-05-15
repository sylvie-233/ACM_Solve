# 15. 三数之和

双指针


```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        for i in range(n):
            target = -nums[i]
            # i去重
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                s = nums[j] + nums[k]
                if s == target:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    while j < n and nums[j] == nums[j - 1]:
                        j += 1
                    k -= 1
                    while k > 0 and nums[k] == nums[k + 1]:
                        k -= 1
                elif s > target:
                    k -= 1
                else:
                    j += 1
        return res
```