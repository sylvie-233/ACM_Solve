# Ruler (hard version)

交互题、三分查找模拟

```c++
#include <iostream>
#include <format>
 
int main() {
    int t, n;
    std::cin >> t;
    while (t--) {
        int l = 1, r = 1000;
        int x = 0, temp;
        int len, q_l, q_r;
        while (l < r) {
            len = (r - l + 1) / 3;
            q_l = l + len;
            q_r = l + 2 * len;
            std::cout << std::format("? {} {}", q_l, q_r) << std::endl;
            std::cout.flush();
            std::cin >> temp;
            if ((q_l + 1) * (q_r + 1) == temp) {
                r = q_l;
            } else if (q_l * (q_r + 1) == temp) {
                l = q_l + 1;
                r = q_r;
            } else {
                l = q_r + 1;
            }
            
        }
        std::cout << std::format("! {}", l) << std::endl;
    }
    return 0;
}
```