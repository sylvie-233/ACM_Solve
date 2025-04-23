# Ruler (easy version)

交互题、二分查找模拟

```c++
#include <iostream>
#include <format>

int main() {
    int t, n;
    std::cin >> t;
    while (t--) {
        int l = 1, r = 1000;
        int x = 0, temp;
        while (l < r) {
            int mid = (l + r) >> 1;
            std::cout << std::format("? {} {}", l, mid) << std::endl;
            std::cout.flush();
            std::cin >> temp;
            if (l * mid == temp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        std::cout << std::format("! {}", l) << std::endl;
    }
    return 0;
}
```