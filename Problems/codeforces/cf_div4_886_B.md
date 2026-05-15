# Ten Words of Wisdom

简单排序

```c++
#include <iostream>

int main() {
    int t, n, a, b;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        int ans_a, ans_b, ans_i;
        ans_a = ans_b = ans_i = -1;
        for (int i = 1; i <= n; i++) {
            std::cin >> a >> b;
            if (a <= 10) {
                if (ans_i == -1) {
                    ans_i = i;
                    ans_a = a;
                    ans_b = b;
                } else {
                    if (b > ans_b) {
                        ans_i = i;
                        ans_a = a;
                        ans_b = b;
                    }
                }
            }
        }
        std::cout << ans_i << std::endl;
    }
    return 0;
}
```