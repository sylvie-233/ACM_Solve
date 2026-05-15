# Bobritto Bandito


简单构造，左右边界判断
```c++
#include <iostream>
#include <cmath>

int main() {
    int t;
    int n, m, l, r;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m >> l >> r;
        int ans_l = 0, ans_r = 0;
        if (m >= r) {
            ans_r = r;
            m -= r;
            if (m >= std::abs(n)) {
                ans_l = l;
            } else {
                ans_l = -m;
            }
        } else {
            ans_r = m;
        }
        std::cout << ans_l << " " << ans_r << std::endl;
    }
    return 0;
}
```