# Skibidus and Ohio

简单分析，只要有相邻的元素，最终最小长度一定为1
```c++
#include <iostream>

int main() {
    int t;
    std::string s;
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        bool flag = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                flag = true;
                break;
            }
        }
        std::cout << (flag ? 1 : s.length()) << std::endl;
    }
    return 0;
}
```
