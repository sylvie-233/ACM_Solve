# 3598. 相邻字符串之间的最长公共前缀

简单模拟

```python
class Solution:
    def longestCommonPrefix(self, words: List[str]) -> List[int]:
        n = len(words)
        if n == 1 or n == 2:
            return [0] * n
        def get_prefix_len(s1: str, s2: str) -> int:
            l = min(len(s1), len(s2))
            for i in range(l):
                if s1[i] != s2[i]:
                    return i 
            return l
        len1 = []
        len2 = []
        for i in range(n - 1):
            len1.append(get_prefix_len(words[i], words[i+1]))
        for i in range(n - 2):
            len2.append(get_prefix_len(words[i], words[i+2]))
        # print(len1, len2)
        
        sorted_len1 = sorted(len1, key=lambda x:-x)
        # print(sorted_len1)

        res = []
        for i in range(n):
            if i == 0:
                l = len1[0]
                mx = sorted_len1[0]
                if mx == l:
                    mx = sorted_len1[1]
                res.append(mx)
            elif i == n - 1:
                l = len1[n - 2]
                mx = sorted_len1[0]
                if mx == l:
                    mx = sorted_len1[1]
                res.append(mx)
            else:
                l1, l2 = sorted([len1[i - 1], len1[i]], key=lambda x:-x)
                l3 = len2[i - 1]
                mx = sorted_len1[0]
                if mx == l1:
                    mx = sorted_len1[1]
                    if mx == l2:
                        mx = sorted_len1[2] if n >= 4 else 0
                mx = max(mx, l3)
                res.append(mx)
        return res
```