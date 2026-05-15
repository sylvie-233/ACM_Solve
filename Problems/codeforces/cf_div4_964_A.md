# A+B Again?

简单构造

```c++
#include <iostream>

int main() {
    int t;
    std::string s;
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        std::cout << (s[0] - '0' + s[1] - '0') << std::endl;
    } 
}
```