# 3593. 使叶子路径成本相等的最小增量

树上dfs + 贪心


```python
class Solution:
    def minIncrease(self, n: int, edges: List[List[int]], cost: List[int]) -> int:
        # 构图
        graph = [[] for _ in range(n)]
        for e in edges:
            u, v = e
            graph[u].append(v)
            graph[v].append(u)
        graph[0].append(-1)

        res = 0
        def dfs(u: int, fa: int) -> int:
            """获取经过该节点到叶子节点的路径path最大值"""
            # print(u, fa)
            # print("-------------------")
            if len(graph[u]) == 1:
                return cost[u]

            mx = cnt = 0
            for v in graph[u]:
                if v == fa:
                    continue
                child_cost = dfs(v, u)
                # 贪心，获取子路径的最大值
                if child_cost > mx:
                    mx = child_cost
                    cnt = 1
                elif child_cost == mx:
                    cnt += 1
                
            nonlocal res
            res += len(graph[u]) - 1 - cnt
            # print(u, mx, cnt, res)
            return cost[u] + mx 
        
        dfs(0, -1)
        return res
```