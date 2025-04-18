# Insane Problem

简单数学计算

```c++
#include <iostream>
 
using ull = unsigned long long;
 
int main() {
    int t;
    int k, l1, r1, l2, r2;
    std::cin >> t;
    while (t--) {
        std::cin >> k >> l1 >> r1 >> l2 >> r2;
        ull k_c = 1;
        ull ans = 0;
        for (int i = 0; i <= 30; i++) {
            ull l = k_c * l1;
            ull r = k_c * r1;
            l = std::max(l, (ull)l2);
            r = std::min(r, (ull)r2);
            if (r >= l) {
                ans += (r / k_c -  (l - 1) / k_c);
            }
 
            k_c = k_c * k;
            if (k_c > r2) break;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```