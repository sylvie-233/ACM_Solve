# 3628. 插入一个字母的最大子序列数

前缀和

```python
class Solution:
    def numOfSubsequences(self, s: str) -> int:
        n = len(s)
        new_s = "_" + s
        pre_L = [0] * (n + 1)
        pre_T = [0] * (n + 1)
        for i in range(1, n + 1):
            pre_L[i] = pre_L[i - 1] + (1 if new_s[i] == 'L' else 0)
            pre_T[i] = pre_T[i - 1] + (1 if new_s[i] == 'T' else 0)

        # print(pre_L)
        # print(pre_T)
        
        pre2_L = [0] * (n + 1)
        for i in range(1, n + 1):
            pre2_L[i] = pre2_L[i - 1] + (pre_L[i - 1] if new_s[i] == 'C' else 0)
        
        # print(pre2_L)
        
        suf2_T = [0] * (n + 1)
        for i in range(n - 1, 0, -1):
            suf2_T[i] = suf2_T[i + 1] + (pre_T[n] - pre_T[i] if new_s[i] == 'C' else 0)
        
        # print(suf2_T)

        res = 0
        for i in range(1, n):
            if new_s[i] == 'C':
                res += pre_L[i - 1] * (pre_T[n] - pre_T[i])
        # print(res)
        # 插入L
        res_L = 0
        for i in range(1, n + 1):
            res_L = max(res_L, suf2_T[i])
        # print(res_L)

        # 插入T
        res_T = 0
        for i in range(1, n + 1):
            res_T = max(res_T, pre2_L[i])
        # print(res_T)

        # 插入C
        res_C = 0
        for i in range(1, n + 1):
            res_C = max(res_C, pre_L[i - 1] * (pre_T[n] - pre_T[i - 1]))
        # print(res_C)
        return res + max(res_C, res_L, res_T)
```