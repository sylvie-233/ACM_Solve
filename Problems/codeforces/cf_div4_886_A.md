# To My Critics

简单构造

```c++
#include <iostream>
#include <format>

int main() {
    int t, a, b, c;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        if ((a + b >= 10) || (a + c >= 10) || (b + c >= 10))
            std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    } 
}
```