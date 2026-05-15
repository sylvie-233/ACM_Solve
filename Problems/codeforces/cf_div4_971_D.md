# Satyam and Counting

简单构造

```c++
#include <iostream>
#include <algorithm>
#include <utility>

using ull = unsigned long long;
constexpr int N = 2e5 + 5;
int arr[N][2];
std::pair<int, int> v[N];
int sum[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> v[i].first >> v[i].second;
            sum[i] = arr[i][0] = arr[i][1] = 0;
        }
        sum[0] = arr[0][0] = arr[0][1] = arr[n + 1][0] = arr[n + 1][1] = 0;
        std::sort(v + 1, v + n + 1, [](auto a, auto b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        for (int i = 1; i <= n; i++) {
            arr[v[i].first][v[i].second]++;
        }
        sum[0] += arr[0][0] + arr[0][1];
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i][0] + arr[i][1];

        ull ans = 0;
        if (arr[0][0] && arr[0][1]) {
            ans += sum[n] - sum[0];
        }
        for (int i = 1; i <= n; i++) {
            if (arr[i][0] && arr[i][1]) ans += sum[i -1] + sum[n] - sum[i];
            if (arr[i][0]) {
                if (arr[i - 1][1] && arr[i + 1][1]) ans++;
            }
            if (arr[i][1]) {
                if (arr[i - 1][0] && arr[i + 1][0]) ans++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```