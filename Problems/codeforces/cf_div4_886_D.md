# Balanced Round

简单构造，最大一维连通块点数

```c++
#include <iostream>
#include <algorithm>

constexpr int N = 2e5 + 5;
int arr[N][2];;
int a[N];

int main() {
    int t, n, k;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        int v = a[1], ans = 1, sz = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] - v <= k) {
                sz++;
            } else {
                sz = 1;
            }
            v = a[i];
            ans = std::max(ans, sz);
        }
        std::cout << n - ans << std::endl;
    }
    return 0;
}
```