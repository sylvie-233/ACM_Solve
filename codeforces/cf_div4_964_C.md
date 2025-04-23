# Showering

简单排序

```c++
#include <algorithm>
#include <iostream>
#include <utility>

const int N = 2e5 + 5;
std::pair<int, int> p[N];

int main() {
    int t, n, s, m;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> s >> m;
        for (int i = 1; i <= n; i++) 
            std::cin >> p[i].first >> p[i].second;
        std::sort(p + 1, p + n + 1);
        bool flag = false;
        if (p[1].first >= s) flag = true;
        else {
            for (int i = 2; i <= n; i++) {
                if (p[i].first - p[i - 1].second >= s) {
                    flag = true;
                    break;
                }
            }
            if (m - p[n].second >= s) {
                flag = true;
            }
        }

        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}
```