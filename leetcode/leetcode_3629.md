# 3629. 通过质数传送到达终点的最少跳跃次数

bfs + 素数筛原理

```python
class Solution:
    def minJumps(self, nums: List[int]) -> int:
        def sieve(n):
            is_prime = [False, False] + [True] * (n - 1)  # 0和1不是质数
            for i in range(2, int(n**0.5) + 1):
                if is_prime[i]:
                    for j in range(i*i, n+1, i):
                        is_prime[j] = False
            return is_prime
        
        N = max(nums)
        is_prime = sieve(N + 5)

        n = len(nums)
        if n == 1:
            return 0
        new_nums = [0] + nums
        index_dict = defaultdict(list)
        for i in range(1, n + 1):
            index_dict[new_nums[i]].append(i)
        
        
        q = deque()
        q.append(1)
        visited = [False] * (n + 1)
        depth = [0] * (n + 1)
        visited[1] = True
        while q:
            u = q.popleft()
            num = new_nums[u]

            # 处理素数倍数的邻接节点
            if is_prime[num]:
                # 遍历num的倍数，动态查找能整除它的索引
                for multiple in range(num, N + 1, num):
                    if multiple in index_dict:
                        for idx in index_dict[multiple]:
                            if not visited[idx]:
                                visited[idx] = True
                                depth[idx] = depth[u] + 1
                                if idx == n:
                                    return depth[idx]
                                q.append(idx)
                        del index_dict[multiple]

            # 处理相邻节点（前一个和后一个）
            if u - 1 >= 1 and not visited[u - 1]:
                visited[u - 1] = True
                depth[u - 1] = depth[u] + 1
                if u - 1 == n:
                    return depth[u - 1]
                q.append(u - 1)
            if u + 1 <= n and not visited[u + 1]:
                visited[u + 1] = True
                depth[u + 1] = depth[u] + 1
                if u + 1 == n:
                    return depth[u + 1]
                q.append(u + 1)
```