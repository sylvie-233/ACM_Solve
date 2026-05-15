# Expected Median

简单组合数学


```c++
#include <iostream>
#include <algorithm>

using ll = long long;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

ll fac[N], inv[N];

// 快速幂
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 初始化阶乘和逆元
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

// C(n, k) = fac[n] * inv[k] * inv[n-k]
ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    int t, n, k, a;
    init();
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        int cnt_1 = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a;
            if (a & 1) cnt_1++;
        }
        ll ans = 0;
        int len = (k - 1) / 2;
        int p_l = std::max(n - cnt_1 + 1, len + 1);
        int p_r = n - len;
        for (int i = p_l; i <= p_r; i++) {
            ans = (ans + C(i - 1, len) * C(n - i, len) % MOD) % MOD;
        }
        std::cout << ans << std::endl;
    }
}
```