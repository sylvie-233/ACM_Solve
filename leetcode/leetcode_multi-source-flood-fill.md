# multi-source-flood-fill


多源BFS
```python
from collections import deque

class Solution:
    def colorGrid(self, n: int, m: int, sources: list[list[int]]) -> list[list[int]]:
        q = deque()
        dist = [[-1]*m for _ in range(n)]
        for i in sources:
            dist[i[0]][i[1]] = i[2] 
            q.append((i[0], i[1]))

        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        # print(dist)

        while True:
            temp_d = dict()
            while q:
                x, y = q.popleft()

                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy

                    if 0 <= nx < n and 0 <= ny < m:
                        if dist[nx][ny] == -1:
                            if (nx, ny) in temp_d:
                                v = temp_d[(nx, ny)]
                                if dist[x][y] > v:
                                    temp_d[(nx, ny)] = dist[x][y]
                            else:
                                temp_d[(nx, ny)] = dist[x][y]

            if not len(temp_d) > 0:
                break

            for key, val in temp_d.items():
                x, y = key
                dist[x][y] = val
                q.append((x, y))

        return dist
```