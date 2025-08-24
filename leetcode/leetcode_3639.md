# 3639. 变为活跃状态的最小时间

简单计数 + 二分查找搜索优化


```python
class SortList:
    def __init__(self):
        self.data = []

    def insert(self, x):
        bisect.insort(self.data, x)

    def next_greater(self, x):
        idx = bisect.bisect_right(self.data, x)
        return self.data[idx] if idx < len(self.data) else None

    def prev_less(self, x):
        idx = bisect.bisect_left(self.data, x)
        return self.data[idx - 1] if idx > 0 else None

class Solution:
    def minTime(self, s: str, order: List[int], k: int) -> int:
        n = len(order)
        cnt = 0
        sortlist = SortList()
        for i in range(n):
            left = sortlist.prev_less(order[i])
            if left is None:
                left = -1
            right = sortlist.next_greater(order[i])
            if right is None:
                right = n
            cnt += (order[i] - left) * (right - order[i])
            # print(left, right, order[i])
            # print(cnt)
            sortlist.insert(order[i])
            if cnt >= k:
                return i
        return -1
```