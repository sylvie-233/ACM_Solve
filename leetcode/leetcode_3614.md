# 3614. 用特殊操作处理字符串 II

逆推模拟

```python
class Solution:
    def processStr(self, s: str, k: int) -> str:
        ops = [('', 0, 0)]
        for c in s:
            if c <= 'z' and c >= 'a':
                ops.append((c, ops[len(ops) -1][1] + 1, ops[len(ops) -1][1]))
            elif c == '*':
                if ops[len(ops) -1][1] > 0:
                    ops.append(('*', ops[len(ops) -1][1] - 1, ops[len(ops) -1][1]))
            elif c == '#':
                ops.append(('#', ops[len(ops) -1][1] * 2, ops[len(ops) -1][1]))
            elif c == '%':
                ops.append(('%', ops[len(ops) -1][1], ops[len(ops) -1][1]))

        if k >= ops[len(ops) -1][1]: return "."
        rev_ops = list(reversed(ops))
        # print(rev_ops)
        for i in rev_ops:
            op, l, old_l = i
            # print(op, l, old_l, "-----", k)
            if op <= 'z' and op >= 'a':
                if k == l - 1: return op
            elif op == '*': continue
            elif op == '#': k %= old_l
            elif op == '%': k = old_l - 1 - k
```