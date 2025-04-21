# Klee's SUPER DUPER LARGE Array!!!

二分查找

```c++
#include <iostream>
#include <cmath>
using ll = unsigned long long;

int main() {
    int t;
    ll n, k;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        ll ans = 2e18;
        ll l = k, r = k + n - 1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll l_v = (k + mid) * (mid - k + 1) / 2;
            ll r_v = (mid + 1 + k + n - 1) * (k + n - 1 - mid) / 2;
            if (l_v >= r_v) {
                ans = std::min(ans, l_v - r_v);
                r = mid - 1;
            } else {
                ans = std::min(ans, r_v - l_v);
                l = mid + 1;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```