# Slavic's Exam

简单模拟


```c++
#include <iostream>
#include <algorithm>

int main() {
    int T;
    std::string s, t;
    std::cin >> T;
    while (T--) {
        std::cin >> s >> t;
        int ps = 0;
        bool ans = true;
        for (int i = 0; i < t.size(); i++) {
            if (ps >= s.size()) {
                ans = false;
                break;
            }
            if (s[ps] != t[i]) {
                bool flag = false;
                do {
                    if (s[ps] == '?') {
                        s[ps++] = t[i];
                        flag = true;
                        break;
                    } else if (s[ps] == t[i]) {
                        ps++;
                        flag = true;
                        break;
                    } else {
                        ps++;
                    }
                } while (ps < s.size());
                if (!flag) {
                    ans = false;
                    break;
                }
            } else {
                ps++;
            }
        }
        if (ans) {
            if (ps < s.size()) {
                while (ps < s.size()) {
                    if (s[ps] == '?') s[ps] = 'a';
                    ps++;
                }
            }
            std::cout << "YES" << std::endl;
            std::cout << s << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
```