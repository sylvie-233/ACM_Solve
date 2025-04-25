# 2827. 范围中美丽整数的数目

数位DP


给你正整数 low ，high 和 k 。

如果一个数满足以下两个条件，那么它是 美丽的 ：

偶数数位的数目与奇数数位的数目相同。
这个整数可以被 k 整除。
请你返回范围 [low, high] 中美丽整数的数目。

 

示例 1：

输入：low = 10, high = 20, k = 3
输出：2
解释：给定范围中有 2 个美丽数字：[12,18]
- 12 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
- 18 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
以下是一些不是美丽整数的例子：
- 16 不是美丽整数，因为它不能被 k = 3 整除。
- 15 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
给定范围内总共有 2 个美丽整数。
示例 2：

输入：low = 1, high = 10, k = 1
输出：1
解释：给定范围中有 1 个美丽数字：[10]
- 10 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 1 整除。
给定范围内总共有 1 个美丽整数。
示例 3：

输入：low = 5, high = 5, k = 2
输出：0
解释：给定范围中有 0 个美丽数字。
- 5 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
 

提示：

0 < low <= high <= 109
0 < k <= 20

```python
from functools import lru_cache

class Solution(object):
    @lru_cache(maxsize=2000000)
    def num_dp(self, pos, is_limit, is_leading_zero, s, k, cnt, rem):
        """
        :type pos: int
        :type is_limit: bool
        :type is_leading_zero: bool
        :type s: str
        :rtype: int
        """
        if (pos == len(s)):
            if (not is_leading_zero and cnt == 0 and rem == 0):
                return 1
            return 0
        max_digit = int(s[pos]) if is_limit else 9
        res = 0
        for i in range(max_digit + 1):
            cnt_t = 0
            if i != 0 or not is_leading_zero:
                if i % 2 == 0:
                    cnt_t += 1
                else:
                    cnt_t -= 1
            res += self.num_dp(pos + 1, is_limit and (i == max_digit), is_leading_zero and (i == 0), s, k, cnt + cnt_t, (rem * 10 + i) % k)
        return res

    def numberOfBeautifulIntegers(self, low, high, k):
        """
        :type low: int
        :type high: int
        :type k: int
        :rtype: int
        """
        ans_r = self.num_dp(0, True, True, str(high), k, 0, 0)
        ans_l = self.num_dp(0, True, True, str(low - 1), k, 0, 0)
        return ans_r - ans_l   
```