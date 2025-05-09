# 1383. 最大的团队表现值

二维贪心，先排序消去一维，利用优先队列维护第二维的最大值（易错点：不一定要取k个）


```python
import heapq

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        arr = [[efficiency[i], speed[i]] for i in range(n)]
        arr = sorted(arr, key=lambda item: item[0], reverse=True)

        min_heap = []
        speed_sum = 0
        res = 0

        if k == 1:
            for i in range(n):
                res = max(res, arr[i][0] * arr[i][1])
        else:
            # 前k-1个最大的speed
            for i in range(k-1):
                heapq.heappush(min_heap, arr[i][1])
                speed_sum += arr[i][1]
                # 可能中间过程（没取k个）就已经最大了
                res = max(res, speed_sum * arr[i][0])
            
            # 二维贪心维护
            for i in range(k-1, n):
                res = max(res, (speed_sum + arr[i][1]) * arr[i][0])
                if arr[i][1] > min_heap[0]:
                    speed_sum -= min_heap[0]
                    speed_sum += arr[i][1]
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, arr[i][1])
            
        return res % (10**9 + 7)
```