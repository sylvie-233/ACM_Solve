# 100982. 开销小于等于 K 的子数组数目


双指针
```python
class SparseTable:
    def __init__(self, arr):
        self.n = len(arr)
        self.log = [0] * (self.n + 1)

        for i in range(2, self.n + 1):
            self.log[i] = self.log[i // 2] + 1

        k = self.log[self.n] + 1

        self.st_max = [[0] * k for _ in range(self.n)]
        self.st_min = [[0] * k for _ in range(self.n)]

        for i in range(self.n):
            self.st_max[i][0] = arr[i]
            self.st_min[i][0] = arr[i]

        j = 1
        while (1 << j) <= self.n:
            for i in range(self.n - (1 << j) + 1):
                self.st_max[i][j] = max(
                    self.st_max[i][j - 1], self.st_max[i + (1 << (j - 1))][j - 1]
                )
                self.st_min[i][j] = min(
                    self.st_min[i][j - 1], self.st_min[i + (1 << (j - 1))][j - 1]
                )
            j += 1

    def query_max(self, l, r):
        k = self.log[r - l + 1]
        return max(self.st_max[l][k], self.st_max[r - (1 << k) + 1][k])

    def query_min(self, l, r):
        k = self.log[r - l + 1]
        return min(self.st_min[l][k], self.st_min[r - (1 << k) + 1][k])


class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        n = len(nums)
        st = SparseTable(nums)
        ans = 0
        p = 0
        for i in range(n):
            while (
                p <= i
                and (st.query_max(p, i) - st.query_min(p, i))
                * (i - p + 1)
                > k
            ):
                p += 1
            ans += i - p + 1

        return ans
```