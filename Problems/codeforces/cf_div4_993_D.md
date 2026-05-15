# Harder Problem

简单构造，贪心，按最小次数不重复元素进行构造

```c++
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
 
 
constexpr int N = 2e5 + 5;
int arr[N];
int ans[N];
 
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::set<int> st;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            st.insert(arr[i]);
        }
        int m = st.size();
        std::set<int> copy;
        copy.insert(st.begin(), st.end());
        // 按最小次数进行构造
        for (int i = 0; i < n; i++) {
            if (copy.count(arr[i]) != 0) {
                ans[i] = arr[i];
                copy.erase(arr[i]);
                // 重新下一轮构造
                if (copy.size() == 0) {
                    copy.insert(st.begin(), st.end());
                }
            } else {
                ans[i] = *copy.begin();
                copy.erase(*copy.begin());
                if (copy.size() == 0) {
                    copy.insert(st.begin(), st.end());
                }
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
```