# Medium Demon Problem (easy version)

tarjan有向图缩点 + 拓扑模拟 去点（有向图最长路径？）

```c++
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

constexpr int N = 2e5 + 5;
std::vector<int> g[N];
int r[N];
int dfn[N], low[N], sz[N], indeg[N], timestamp;
bool inStack[N];
int scc_id[N], scc_cnt;
std::stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    inStack[u] = true;
    int v = r[u];
    if (!dfn[v]) {
        tarjan(v);
        low[u] = std::min(low[u], low[v]);
    } else if (inStack[v]) {
        low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int v;
        do {
            v = stk.top();
            stk.pop();
            inStack[v] = false;
            scc_id[v] = scc_cnt;
            sz[scc_cnt]++;
        } while(v != u);
    }
}

int main() {
    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> r[i];
            inStack[i] = false;
            dfn[i] = sz[i] = indeg[i] = 0;
            g[i].clear();
        }
        stk = std::stack<int>();
        timestamp = scc_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) tarjan(i);
        }
        // tarjan缩点构图
        for (int i = 1; i <= n; i++) {
            if (scc_id[i] != scc_id[r[i]]) {
                g[scc_id[i]].push_back(scc_id[r[i]]);
                indeg[scc_id[r[i]]]++;
            }
        }
        int ans = 2;
        // 拓扑模拟 去点
        std::queue<int> que;
        for (int i = 1; i <= scc_cnt; i++) {
            if (indeg[i] == 0 && sz[i] == 1) que.push(i);
        }
        while (!que.empty()) {
            std::queue<int> copy;
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i];
                    if (--indeg[v] == 0 && sz[v] == 1) {
                        copy.push(v);
                    }
                }
            }
            ans++;
            que.swap(copy);
        }
        std::cout << ans << std::endl;
    }
}
```