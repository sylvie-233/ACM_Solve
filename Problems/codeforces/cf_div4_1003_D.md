# Skibidus and Sigma

数学分析
整段区间排序后的得分最大值，分析`a[i]a[j]` 和 `a[j]a[i]`交换顺序后对总得分的影响（作差分析），发现，最终影响总得分的是 区间原来的总和sum
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

constexpr int N = 2e5 + 5;
int a[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        long long sum = 0;
        std::vector<std::pair<long long, int>> arr;
        for (int i = 1; i <= n * m; i++) {
            std::cin >> a[i];
            // 每个区间求和
            sum += a[i];
            if (i % m == 0) {
                // 记录每段区间的sum和标号
                arr.push_back(std::make_pair(sum, i / m));
                sum = 0;
            }
        }

        // 根据sum从大到小排序
        std::sort(arr.begin(), arr.end(), [](auto a, auto b) {
            return a.first > b.first;
        });
        long long ans = 0, p =  n * m;
        // for (int i = 0; i < arr.size(); i++) {
        //     std::cout << arr[i].second << " ";
        // }
        // std::cout << std::endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 计算最终得分
                ans += p * a[j + (arr[i - 1].second - 1) * m];
                p--;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
```