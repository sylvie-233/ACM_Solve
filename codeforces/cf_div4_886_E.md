# Cardboard for Pictures	

简单数学，求根公式

```c++
#include <iostream>
#include <cmath>

using ull = unsigned long long;
const int N = 2e5 + 5;

int main() {
    int t, n;
    long double c, s;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> c;
        long double f_a = 0, f_b = 0, f_c = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> s;
            f_b += s;
            f_c += s * s;
        }
        f_a = 4 * n;
        f_b *= 4;
        f_c -= c;
        ull ans = ((std::sqrt(f_b * f_b - 4 * f_a * f_c)) - f_b) / (2 * f_a);
        std::cout << ans << std::endl;
    }
    return 0;
}
```