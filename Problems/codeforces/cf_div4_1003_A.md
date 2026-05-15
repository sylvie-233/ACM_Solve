# Skibidus and Amog'u

简单构造
```c++
#include <iostream>
#include <format>

int main() {
    int t;
    std::cin >> t;
    std::string s;
    while (t--) {
        std::cin >> s;
        std::cout << s.substr(0, s.length() - 2) + "i" << std::endl;
    } 
}
```