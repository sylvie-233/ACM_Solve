# Hard Problem

简单分析

```c++
#include <algorithm>
#include <iostream>
 
int main() {
    int t;
    int m, a, b, c;
    std::cin >> t;
    while (t--) {
        std::cin >> m >> a >> b >> c;
        int m1, m2;
        m1 = m2 = m;
        int ans = 0;
        if (m >= a) {
            ans += a;
            m1 -= a;
        } else {
            ans += m;
            m1 = 0;
        }
        if (m >= b) {
            ans += b;
            m2 -= b;
        } else {
            ans += m;
            m2 = 0;
        }
        ans += std::min(m1 + m2, c);
        std::cout << ans << std::endl;
    }
    return 0;
}
```