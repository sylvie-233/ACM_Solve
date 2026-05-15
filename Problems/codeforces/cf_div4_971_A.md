# Minimize!

简单分析

```c++
#include <iostream>
#include <format>

int main() {
    int t, a, b;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b;
        std::cout << b - a << std::endl;
    } 
}
```