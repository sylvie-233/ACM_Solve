# Word on the Paper

简单搜索，DFS

```c++
#include <algorithm>
#include <iostream>

const int N = 10;
char g[N][N];
int d[3] = {-1, 0, 1};

std::string dfs(int i, int j) {
    std::string res = "";
    res += g[i][j];
    if (i == 7) return res;
    for (int k = 0; k < 3; k++) {
        if ((j + d[k] >= 0) && (j + d[k] <= 7) && (g[i + 1][j + d[k]] != '.')) {
            res += dfs(i + 1, j + d[k]);
            break;
        }
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::cin >> g[i][j];
            }
        }
        std::string ans = "";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (g[i][j] != '.') {
                    ans = dfs(i, j);
                    break;
                }
            }
            if (ans != "") break;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```