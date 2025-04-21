# osu!mania

简单构造

```c++
#include <iostream>

const int N = 505;
std::string arr[N];

int main() {
    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (arr[i][j] == '#') {
                    std::cout << j + 1 << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
```