# 3845. 最大子数组异或值


滑动窗口 + 01字典树
```python
from itertools import accumulate
from operator import xor
from collections import deque
from typing import List, Optional

WIDTH = 15  # nums[i] 二进制长度的最大值


class Node:
    __slots__ = ("son", "leaf")

    def __init__(self):
        self.son: List[Optional[Node]] = [None, None]
        self.leaf: int = 0


class Trie:
    def __init__(self):
        self.root: Node = Node()

    def put(self, val: int) -> None:
        cur = self.root

        for i in range(WIDTH - 1, -1, -1):
            bit = (val >> i) & 1

            if cur.son[bit] is None:
                cur.son[bit] = Node()

            nxt = cur.son[bit]
            assert nxt is not None

            cur = nxt
            cur.leaf += 1

    def delete(self, val: int) -> None:
        cur = self.root

        for i in range(WIDTH - 1, -1, -1):
            bit = (val >> i) & 1

            nxt = cur.son[bit]
            assert nxt is not None

            cur = nxt
            cur.leaf -= 1

    def max_xor(self, val: int) -> int:
        cur = self.root
        ans = 0

        for i in range(WIDTH - 1, -1, -1):
            bit = (val >> i) & 1

            other = cur.son[bit ^ 1]

            if other is not None and other.leaf > 0:
                ans |= 1 << i
                bit ^= 1

            nxt = cur.son[bit]
            assert nxt is not None

            cur = nxt

        return ans


class Solution:
    def maxXor(self, nums: list[int], k: int) -> int:
        pre = list(accumulate(nums, xor, initial=0))

        t = Trie()
        min_q = deque()
        max_q = deque()
        ans = left = 0
        for right, x in enumerate(nums):
            # 1. 入
            t.put(pre[right])

            while min_q and x <= nums[min_q[-1]]:
                min_q.pop()
            min_q.append(right)

            while max_q and x >= nums[max_q[-1]]:
                max_q.pop()
            max_q.append(right)

            # 2. 出
            while nums[max_q[0]] - nums[min_q[0]] > k:
                t.delete(pre[left])
                left += 1
                if min_q[0] < left:
                    min_q.popleft()
                if max_q[0] < left:
                    max_q.popleft()

            # 3. 更新答案
            ans = max(ans, t.max_xor(pre[right + 1]))
        return ans
```