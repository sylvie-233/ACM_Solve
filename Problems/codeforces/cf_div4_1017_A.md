# Trippi Troppi

简单构造、格式化输出
```c++
#include <iostream>
#include <format>

int main() {
    int t;
    std::cin >> t;
    std::string a, b, c;
    while (t--) {
        std::cin >> a >> b >> c;
        std::cout << std::format("{}{}{}", a[0], b[0], c[0]) << std::endl;
    } 
}
```
