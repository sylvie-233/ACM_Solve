# Medium Demon Problem (hard version)

tarjan有向图缩点，dfs最大子树
```c++
#include <iostream>
#include <algorithm>
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

int dfs(int u) {
    int res = 1;
    for (int i = 0; i < g[u].size(); i++) {
        res += dfs(g[u][i]);
    }
    return res;
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
        // tarjan有向图缩点
        for (int i = 1; i <= n; i++) {
            if (scc_id[i] != scc_id[r[i]]) {
                g[scc_id[r[i]]].push_back(scc_id[i]);
                indeg[scc_id[i]]++;
            }
        }
        // dfs最大子树
        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++) {
            int mx = 0;
            if (indeg[i] == 0) {
                for (int j = 0; j < g[i].size(); j++) {
                    mx = std::max(mx, dfs(g[i][j]));
                }
            }
            ans = std::max(ans, mx);
        }
        std::cout << ans + 2 << std::endl;
    }
}
```