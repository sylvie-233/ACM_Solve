# 100970. 移除至多一个元素后的最长交替子数组


DP、前后缀分解
```python
class Solution:
    def longestAlternating(self, nums: list[int]) -> int:
        n = len(nums)
        dp_left = [[1, 1] for _ in range(n)]
        dp_right = [[1, 1] for _ in range(n)]
        ans = 1
        # 从左往右遍历
        for i in range(1, n):
            if nums[i] == nums[i - 1]:
                continue
            elif nums[i] > nums[i - 1]:
                dp_left[i][0] = dp_left[i - 1][1] + 1
            else:
                dp_left[i][1] = dp_left[i - 1][0] + 1
            ans = max(ans, dp_left[i][0], dp_left[i][1])

            # 从右往左遍历
        for i in range(n - 2, -1, -1):
            if nums[i] == nums[i + 1]:
                continue
            elif nums[i] > nums[i + 1]:
                dp_right[i][0] = dp_right[i + 1][1] + 1
            else:
                dp_right[i][1] = dp_right[i + 1][0] + 1

        # print(ans)
        for i in range(1, n - 1):
            if nums[i - 1] < nums[i + 1]:
                ans = max(ans, dp_left[i - 1][1] + dp_right[i + 1][0])
            elif nums[i - 1] > nums[i + 1]:
                ans = max(ans, dp_left[i - 1][0] + dp_right[i + 1][1])
            # print(ans)

        return ans
```