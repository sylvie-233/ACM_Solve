# Brr Brrr Patapim


有向无环图最长路径
拓扑排序 + dp
```c++
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> e[1605];
int indeg[1605];
int dp[1605];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            e[i].clear();
            indeg[i] = 0;
            dp[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            int x, pre = -1;
            for (int j = 1; j <= n; j++) {
                std::cin >> x;
                if (pre != -1) {
                    e[pre].push_back(x);
                    indeg[x]++;
                }
                pre = x;
                // 存在的点记为0
                dp[x] = 0;
            }
        }

        // 入度为0的点入队列
        std::queue<int> que;
        for (int i = 1; i <= 2 * n; i++) {
            if (indeg[i] == 0 && dp[i] != -1) {
                que.push(i);
            }
        }

        // BFS，拓扑排序计算长度
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            for (int i : e[p]) {
                dp[i] = std::max(dp[i], dp[p] + 1);
                if (--indeg[i] == 0) {
                    que.push(i);
                }
            }
        }
        std::vector<std::pair<int, int>> ans;
        for (int i = 1; i <= 2 * n; i++) {
            ans.push_back(std::make_pair(i, dp[i]));
        }

        // 根据路径对点进行排序
        std::sort(ans.begin(), ans.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second < b.second;
        });

        // 输出
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i].first << " ";
        }
        std::cout << std::endl;
    }
}
```