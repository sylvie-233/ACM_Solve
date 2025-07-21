# 3. 无重复字符的最长子串

双指针

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        res = 0
        st = set()
        for i, x in enumerate(s):
            while x in st and left <= i:
                st.remove(s[left])
                left += 1
            st.add(x)
            res = max(res, i - left + 1)
        return res
```