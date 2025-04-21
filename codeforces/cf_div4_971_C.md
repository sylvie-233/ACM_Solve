# The Legend of Freya the Frog

简单分析

```c++
#include <algorithm>
#include <iostream>

int main() {
    int t;
    int x, y, k;
    std::cin >> t;
    while (t--) {
        std::cin >> x >> y >> k;
        int x_s = x / k + (x % k == 0 ? 0 : 1);
        int y_s = y / k + (y % k == 0 ? 0 : 1);
        if (x_s > y_s) std::cout << 2 * (x_s) - 1 << std::endl;
        else std::cout << 2 * y_s << std::endl;
    }
    return 0;
}
```