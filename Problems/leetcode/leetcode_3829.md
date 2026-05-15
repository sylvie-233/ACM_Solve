# 3829. 设计共享出行系统


模拟
```python
class RideSharingSystem:
    def __init__(self):
       self.rider = []
       self.driver = []
       self.exist = Counter()
       self.counter = Counter()

    def addRider(self, riderId: int) -> None:
        self.rider.append(riderId)
        self.exist[riderId] += 1

    def addDriver(self, driverId: int) -> None:
        self.driver.append(driverId)

    def matchDriverWithRider(self) -> list[int]:
        while len(self.rider) > 0 and self.counter[self.rider[0]] > 0:
            self.rider = self.rider[1:]
        ans = [-1, -1]
        if len(self.rider) > 0 and len(self.driver) > 0:
            ans = [self.driver[0], self.rider[0]]
            self.rider = self.rider[1:]
            self.driver = self.driver[1:]
        return ans
        

    def cancelRider(self, riderId: int) -> None:
        if self.exist[riderId] > 0:
            self.counter[riderId] += 1
```