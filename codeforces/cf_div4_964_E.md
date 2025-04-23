# Triple Operations

简单数学计算


```c++
#include <iostream>
#include <utility>

using ll = long long;
std::pair<int, int> p[105];
int cnt = 0;

void init() {
    int p_l = 0, p_r = 3;
    while (p_r < 2e5) {
        cnt++;
        p[cnt].first = p_l;
        p[cnt].second = p_r - 1;
        p_l = p_r;
        p_r *= 3;
    }
    cnt++;
    p[cnt].first = p_l;
    p[cnt].second = p_r - 1;
}

int find_index(int x) {
    int res = 0;
    for (int i = 1; i <= cnt; i++) {
        if (x >= p[i].first && x <= p[i].second) {
            res = i;
            break;
        }
    }
    return res;
}

int main() {
    int t, l, r;
    init();
    std::cin >> t;
    while (t--) {
        std::cin >> l >> r;
        int p_l = find_index(l);
        int p_r = find_index(r);
        ll ans = 0;
        if (p_l != p_r) {
            ans += (ll)1 * (p[p_l].second - l + 1) * p_l;
            for (int i = p_l + 1; i < p_r; i++) {
                ans += (ll)1 * (p[i].second - p[i].first + 1) * i;
            }
            ans += (ll)1 * (r - p[p_r].first + 1) * p_r;
        } else {
            ans += (ll)1 * (r - l + 1) * p_l;
        }
        ans += p_l;
        std::cout << ans << std::endl;
    }
    return 0;
}
```