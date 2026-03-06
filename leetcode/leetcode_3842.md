# 3842. 切换打开灯泡


```python
class Solution:
    def toggleLightBulbs(self, bulbs: list[int]) -> list[int]:
        counter = [0 for _ in range(101)]
        for i in bulbs:
            counter[i] = counter[i] ^ 1
        return [i for i, v in enumerate(counter) if v == 1]
```