# We Were Both Children

暴力，约数个数统计

```c++
#include <iostream>
#include <vector>
#include <map>

const int N = 2e5 + 5;
std::vector<int> v[N];

void init() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j+=i) {
            v[j].push_back(i);
        }
}

int main() {
    int t, n, a;
    std::cin >> t;
    init();
    while (t--) {
        std::cin >> n;
        std::map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            std::cin >> a;
            if (!mp.count(a)) {
                mp[a] = 1;
            } else {
                mp[a] = mp[a] + 1;
            }
        }
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            int cnt = 0;
            for (int j = 0; j < v[i].size(); j++) {
                cnt += mp[v[i][j]];
            }
            ans = std::max(ans, cnt);
        }
        std::cout << ans << std::endl;
    }
}
```