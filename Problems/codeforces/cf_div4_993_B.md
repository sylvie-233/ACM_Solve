# Normal Problem

简单构造

```c++
#include <iostream>
 
int main() {
    int t;
    std::string s;
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        std::string ans = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'p') ans += "q";
            else if (s[i] == 'q') ans += "p";
            else ans += "w";
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```