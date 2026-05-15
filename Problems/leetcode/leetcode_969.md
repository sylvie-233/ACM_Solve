# 969. 煎饼排序

简单构造

```python
class Solution:
    def pancakeSort(self, arr: list[int]) -> list[int]:
        res = []
        length = len(arr)
        def rev(start: int, end: int):
            while start < end:
                arr[start], arr[end] = arr[end], arr[start]
                start += 1
                end -= 1
        for i in range(length - 1, -1, -1):
            p = i
            for j in range(i, -1, -1):
                if arr[j] > arr[p]:
                    p = j
            if p == i:
                continue
            res.append(p + 1)
            rev(0, p)
            res.append(i + 1)
            rev(0, i)

        return res
```