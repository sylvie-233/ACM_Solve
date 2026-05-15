# 1381. 设计一个支持增量操作的栈

简答数据结构、栈

```python
class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.index = 0
        self.arr = [0] * maxSize
    
    def push(self, x: int) -> None:
        if self.index <= self.maxSize - 1:
            self.arr[self.index] = x
            self.index += 1

    def pop(self) -> int:
        if self.index != 0:
            self.index -= 1
            return self.arr[self.index]
        return -1

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.index)):
            self.arr[i] += val        

# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```