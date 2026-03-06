# 3844. 最长的准回文子字符串


回文串判断
```python
class Solution:
    def almostPalindromic(self, s: str) -> int:
        n = len(s)
        ans = 0
        def expand(l: int, r: int):
            nonlocal ans
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            ans = max(ans, r - l - 1)
        
        for i in range(2 * n - 1):
            l, r = i // 2, (i + 1) // 2
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            expand(l-1, r)
            expand(l, r+1)
            if ans >= n:
                return n
        return ans 
```