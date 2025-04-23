# Card Game

简单分析

```c++
#include <iostream>


int main() {
    int t, a1, a2, b1, b2;
    std::cin >> t;
    while (t--) {
        std::cin >> a1 >> a2 >> b1 >> b2;
        int ans = 0, ra = 0, rb = 0;
        if (a1 > b1) ra++;
        else if (b1 > a1) rb++; 
        if (a2 > b2) ra++;
        else if (b2 > a2) rb++;
        if (ra > rb) ans += 2;

        ra = rb = 1;
        if (a1 > b2) ra++;
        else if (b2 > a1) rb++; 
        if (a2 > b1) ra++;
        else if (b1 > a2) rb++;
        if (ra > rb) ans += 2;
        std::cout << ans << std::endl;
    }
    return 0;
}
```