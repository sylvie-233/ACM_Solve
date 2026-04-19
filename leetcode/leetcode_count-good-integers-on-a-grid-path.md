# count-good-integers-on-a-grid-path


数位DP
```python
from functools import lru_cache

class Solution:
    @staticmethod
    def get_pos(s: str) -> set[int]:
        st = set()
        st.add(0)
        p = 0
        for c in s:
            if c == "D":
                p += 4
            else:
                p += 1
            st.add(p)
        return st

    @staticmethod
    def count_num(n: int, s: set[int]) -> int:
        digits = list(map(int, f"{n:016d}"))

        @lru_cache(maxsize=None)
        def dfs(pos: int, tight: bool, lead: bool, prev: int) -> int:
            """
            pos: 当前处理到第几位
            tight: 是否受原数字上限限制
            lead: 是否还在前导零状态
            prev: 前一位选的数字（用来判断：当前位 >= 前一位）
            """
            # 所有位处理完，合法
            if pos == len(digits):
                return 1

            res = 0
            up = digits[pos] if tight else 9  # 当前位能选的最大值
            in_pos = pos in s

            # 枚举当前位可以选的数字 d
            for d in range(0, up + 1):
                # 条件1：在受限位中，必须>prev前面选择
                if in_pos and d < prev:
                    continue

                # 下一个状态
                next_tight = tight and (d == up)
                next_lead = lead and (d == 0)
                next_prev = d if in_pos else prev  # 前导零则 prev 保持 0

                res += dfs(pos + 1, next_tight, next_lead, next_prev)

            return res

        # 初始状态：第0位，受限，前导零，前一位数字设为 0
        return dfs(0, True, True, 0)

    def countGoodIntegersOnPath(self, l: int, r: int, directions: str) -> int:
        s = Solution.get_pos(directions)
        return Solution.count_num(r, s) - Solution.count_num(l-1, s)
```