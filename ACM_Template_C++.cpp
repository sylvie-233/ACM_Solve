#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <cassert>
#include <format>
#include <string>
#include <vector>
#include <array>
#include <stack>

// 类型别名
using ll = long long;
using ull = unsigned long long;
// 内置工具使用使用
using std::string;


// 数学库
namespace Math {
    // 大数运算
    class BigInt {
    private:
        string num; // 存储数字，正数形式
        bool negative; // 是否为负数

        // 内部辅助函数：比较两个正数的大小
        static int compareAbs(const string &a, const string &b) {
            if (a.size() != b.size()) return a.size() > b.size() ? 1 : -1;
            for (size_t i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) return a[i] > b[i] ? 1 : -1;
            }
            return 0;
        }

        // 内部辅助函数：正数加法
        static string addStrings(const string &a, const string &b) {
            string A = a, B = b;
            if (A.size() < B.size()) std::swap(A, B);
            std::reverse(A.begin(), A.end());
            std::reverse(B.begin(), B.end());
            int carry = 0;
            string res;
            for (size_t i = 0; i < A.size(); ++i) {
                int sum = A[i] - '0' + carry;
                if (i < B.size()) sum += B[i] - '0';
                res += (sum % 10) + '0';
                carry = sum / 10;
            }
            if (carry) res += carry + '0';
            std::reverse(res.begin(), res.end());
            return res;
        }

        // 内部辅助函数：正数减法 (a >= b)
        static string subStrings(const string &a, const string &b) {
            string A = a, B = b;
            std::reverse(A.begin(), A.end());
            std::reverse(B.begin(), B.end());
            int borrow = 0;
            string res;
            for (size_t i = 0; i < A.size(); ++i) {
                int diff = A[i] - '0' - borrow;
                if (i < B.size()) diff -= B[i] - '0';
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else borrow = 0;
                res += diff + '0';
            }
            while (res.size() > 1 && res.back() == '0') res.pop_back();
            std::reverse(res.begin(), res.end());
            return res;
        }

    public:
        // 构造函数
        BigInt(ll x = 0) {
            if (x < 0) {
                negative = true;
                x = -x;
            } else {
                negative = false;
            }
            num = std::to_string(x);
        }

        BigInt(const string &s) {
            if (s[0] == '-') {
                negative = true;
                num = s.substr(1);
            } else {
                negative = false;
                num = s;
            }
        }

        // 输出字符串
        string toString() const {
            return (negative && num != "0" ? "-" : "") + num;
        }

        // 加法
        BigInt operator+(const BigInt &b) const {
            if (negative == b.negative)
                return BigInt((negative ? "-" : "") + addStrings(num, b.num));
            else {
                int cmp = compareAbs(num, b.num);
                if (cmp == 0) return BigInt(0);
                if (cmp > 0)
                    return BigInt((negative ? "-" : "") + subStrings(num, b.num));
                else
                    return BigInt((b.negative ? "-" : "") + subStrings(b.num, num));
            }
        }

        // 减法
        BigInt operator-(const BigInt &b) const {
            BigInt temp = b;
            temp.negative = !temp.negative;
            return *this + temp;
        }

        // 乘法
        BigInt operator*(const BigInt &b) const {
            std::vector<int> res(num.size() + b.num.size(), 0);
            string A = num, B = b.num;
            std::reverse(A.begin(), A.end());
            std::reverse(B.begin(), B.end());
            for (size_t i = 0; i < A.size(); ++i)
                for (size_t j = 0; j < B.size(); ++j)
                    res[i + j] += (A[i] - '0') * (B[j] - '0');
            for (size_t i = 0; i < res.size(); ++i) {
                if (res[i] >= 10) {
                    res[i + 1] += res[i] / 10;
                    res[i] %= 10;
                }
            }
            while (res.size() > 1 && res.back() == 0) res.pop_back();
            string ans;
            for (int i = res.size() - 1; i >= 0; --i) ans += res[i] + '0';
            BigInt result(ans);
            result.negative = negative != b.negative && ans != "0";
            return result;
        }

        // 除法 (大数 / int)
        BigInt operator/(int b) const {
            string res;
            int r = 0;
            for (char c : num) {
                r = r * 10 + (c - '0');
                res += (r / b) + '0';
                r %= b;
            }
            size_t pos = res.find_first_not_of('0');
            if (pos != string::npos) res = res.substr(pos);
            else res = "0";
            BigInt result(res);
            result.negative = negative && res != "0";
            return result;
        }

        // 取模 (大数 % int)
        int operator%(int b) const {
            int r = 0;
            for (char c : num) r = (r * 10 + (c - '0')) % b;
            return negative ? -r : r;
        }

        // 比较运算符
        bool operator<(const BigInt &b) const {
            if (negative != b.negative) return negative;
            int cmp = compareAbs(num, b.num);
            return negative ? cmp > 0 : cmp < 0;
        }

        bool operator>(const BigInt &b) const { return b < *this; }
        bool operator<=(const BigInt &b) const { return !(*this > b); }
        bool operator>=(const BigInt &b) const { return !(*this < b); }
        bool operator==(const BigInt &b) const { return num == b.num && negative == b.negative; }
        bool operator!=(const BigInt &b) const { return !(*this == b); }
    };
    
    // 快速幂 计算 a^b % mod
    ll qpow(ll a, ll b, ll mod) {
        ll res = 1;
        a %= mod; // 先对底数取模，防止溢出

        while (b) {
            if (b & 1) res = res * a % mod;  // 如果当前位是1，则乘上a
            a = a * a % mod; // a 每轮平方
            b >>= 1; // b 右移一位，相当于除以2
        }
        return res;
    }

    // gcd 最大公约数
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

// 搜索库
namespace Searching {
    // 二分查找 在升序序列中二分查找某数 x 的位置，二分区间为 [left,right]，如果不存在，返回-1
    int binary_search(int arr[], int left, int right, int v) {
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arr[mid] == v) return mid;
            else if (arr[mid] < v) left = mid + 1;
            else right = mid -1;
        }
        return -1;
    }
}

// 离散化库
namespace Discretization {
    // 对数组 a[1..n] 进行离散化
    // 返回离散化后的 vals（去重排序后的值域）
    std::vector<int> discretize(int a[], int n) {
        std::vector<int> vals(a + 1, a + n + 1);

        // 排序 + 去重
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

        // 替换为离散化编号
        for (int i = 1; i <= n; ++i) {
            // a数组修改为值域表中的编号
            a[i] = std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
            // 如果你想让离散化从 0 开始就删掉 +1
        }

        return vals;  // 返回值域表
    }
}

// 排序库
namespace Sorting {
    // 冒泡排序 默认升序）
    template <typename T>
    void bubble_sort(T arr[], int n, bool ascending = true) {
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // 提前退出
        }
    }
}

namespace PrefixSum {
    class PrefixSum2D {
    private:
        int n, m;
        std::vector<std::vector<ll>> a;   // 原矩阵 (1-based)
        std::vector<std::vector<ll>> ps;  // 前缀和矩阵 (1-based)

    public:
        // 构造函数
        PrefixSum2D(int _n, int _m) : n(_n), m(_m) {
            a.assign(n + 1, std::vector<ll>(m + 1, 0));
            ps.assign(n + 1, std::vector<ll>(m + 1, 0));
        }

        // 从外部矩阵构建（矩阵下标为 1-based；若是 0-based，请先偏移）
        void initFromMatrix(const std::vector<std::vector<ll>>& mat) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    a[i][j] = mat[i][j];
                }
            }
        }

        // 单点加入 —— 若你逐个读输入，可直接 add(i,j,val)
        void add(int x, int y, ll v) {
            a[x][y] += v;
        }

        // 构建前缀和（必须在全部 add() 完成后调用一次）
        void build() {
            for (int i = 1; i <= n; i++) {
                ll row_sum = 0;
                for (int j = 1; j <= m; j++) {
                    row_sum += a[i][j];
                    ps[i][j] = ps[i-1][j] + row_sum;
                }
            }
        }

        // 查询 (x1, y1) 到 (x2, y2) 的子矩形和
        ll query(int x1, int y1, int x2, int y2) {
            if (x1 > x2) std::swap(x1, x2);
            if (y1 > y2) std::swap(y1, y2);
            return ps[x2][y2]
                - ps[x1-1][y2]
                - ps[x2][y1-1]
                + ps[x1-1][y1-1];
        }
    };
}

// 差分库
namespace Diff {

    // 一维差分 支持区间加
    struct DiffArray {
        int n;
        std::vector<ll> diff; // 1..n

        // 1) 支持 vector<long long>，a[0] 忽略，1..n
        DiffArray(const std::vector<ll>& a) {
            n = a.size() - 1;          // 假设 a[1..n]
            diff.assign(n + 2, 0);
            for (int i = 1; i <= n; ++i) {
                diff[i] = a[i] - a[i - 1];
            }
        }

        // 2) 支持 C 数组构造（a 为 1..n）
        DiffArray(const ll* a, int _n) {
            n = _n;
            diff.assign(n + 2, 0);
            diff[1] = a[1];
            for (int i = 2; i <= n; ++i) {
                diff[i] = a[i] - a[i - 1];
            }
        }

        // 区间加：对 [l, r] 每个元素加 k
        void add(int l, int r, ll k) {
            diff[l] += k;
            if (r + 1 <= n) diff[r + 1] -= k;
        }

        // 还原并返回 vector（1..n）
        std::vector<ll> result() const {
            std::vector<ll> res(n + 1);
            ll cur = 0;
            for (int i = 1; i <= n; ++i) {
                cur += diff[i];
                res[i] = cur;
            }
            return res;
        }

        // 还原结果写回 C 数组（a[1..n]）
        void write_back(ll* a) const {
            ll cur = 0;
            for (int i = 1; i <= n; ++i) {
                cur += diff[i];
                a[i] = cur;
            }
        }
    };

    // 二维差分 区间加
    struct Diff2D {
        int n, m;
        std::vector<std::vector<int>> diff;

        // 构造空差分矩阵
        Diff2D(int n, int m) : n(n), m(m), diff(n + 2, std::vector<int>(m + 2, 0)) {}

        // 用原始矩阵构造（支持二维 C 数组）
        Diff2D(int a[][1010], int n, int m) : n(n), m(m), diff(n + 2, std::vector<int>(m + 2, 0)) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    insert(i, j, i, j, a[i][j]);
        }

        // 在矩形 (x1, y1) 到 (x2, y2) 加 k
        inline void insert(int x1, int y1, int x2, int y2, int k) {
            diff[x1][y1] += k;
            diff[x2 + 1][y1] -= k;
            diff[x1][y2 + 1] -= k;
            diff[x2 + 1][y2 + 1] += k;
        }

        // 还原得到最终矩阵
        std::vector<std::vector<int>> build() {
            std::vector<std::vector<int>> res(n + 1, std::vector<int>(m + 1, 0));

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    res[i][j] = diff[i][j]
                                + res[i - 1][j]
                                + res[i][j - 1]
                                - res[i - 1][j - 1];
            return res;
        }
    };
}

// 分块库
namespace Block {
    struct SqrtBlock {
        int n, len, numBlocks;
        std::vector<ll> a;       // 原数组
        std::vector<ll> sum;     // 每块的和
        std::vector<ll> lazy;    // 懒标记：整块加

        SqrtBlock(int n): n(n) {
            len = std::sqrt(n) + 1;
            numBlocks = (n + len - 1) / len;

            a.assign(n + 1, 0);
            sum.assign(numBlocks + 1, 0);
            lazy.assign(numBlocks + 1, 0);
        }

        // 从数组构造
        void build() {
            for (int i = 1; i <= n; ++i) {
                sum[(i-1)/len] += a[i];
            }
        }

        // 对块应用 lazy 标记
        void push_down(int b) {
            if (lazy[b] == 0) return;
            int L = b * len + 1;
            int R = std::min(n, (b + 1) * len);
            for (int i = L; i <= R; ++i) a[i] += lazy[b];
            lazy[b] = 0;
        }

        // 单点更新：a[x] = v
        void point_update(int x, ll v) {
            int b = (x - 1) / len;
            push_down(b);
            sum[b] += v - a[x];
            a[x] = v;
        }

        // 区间加：对 [l, r] 所有加 k
        void range_add(int l, int r, ll k) {
            int bl = (l - 1) / len;
            int br = (r - 1) / len;

            if (bl == br) {
                push_down(bl);
                for (int i = l; i <= r; ++i) {
                    a[i] += k;
                    sum[bl] += k;
                }
                return;
            }

            // 左边块
            push_down(bl);
            for (int i = l; (i - 1) / len == bl; ++i) {
                a[i] += k;
                sum[bl] += k;
            }

            // 中间整块
            for (int b = bl + 1; b < br; ++b) {
                lazy[b] += k;
                sum[b] += k * len;
            }

            // 右边块
            push_down(br);
            for (int i = r; (i - 1) / len == br; --i) {
                a[i] += k;
                sum[br] += k;
            }
        }

        // 区间查询：求 [l, r] 的和
        ll range_query(int l, int r) {
            ll res = 0;
            int bl = (l - 1) / len;
            int br = (r - 1) / len;

            if (bl == br) {
                push_down(bl);
                for (int i = l; i <= r; ++i) res += a[i];
                return res;
            }

            // 左边块散点
            push_down(bl);
            for (int i = l; (i - 1) / len == bl; ++i) res += a[i];

            // 中间整块
            for (int b = bl + 1; b < br; ++b) {
                res += sum[b];
            }

            // 右边块散点
            push_down(br);
            for (int i = r; (i - 1) / len == br; --i) res += a[i];

            return res;
        }
    };
}


// 莫队库
namespace MoAlgo {

    // 查询条件
    struct Query {
        int l, r, id;
    };

    // 区间不同个数统计
    struct Mo {
        int n;                    // 数组大小
        int block;                // 块大小
        std::vector<int> a;            // 原数组
        std::vector<Query> qs;         // 查询
        std::vector<int> cnt, ans;     // 计数数组与答案 cnt记录当前统计范围 元素值 的个数
        int distinct = 0;         // 当前答案

        Mo(int n, const std::vector<int>& arr, int maxA)
            : n(n), a(arr) {
            block = sqrt(n); // 平方分块
            cnt.assign(maxA + 1, 0);
        }

        void addQuery(int l, int r, int id) {
            qs.push_back({l, r, id});
        }

        // 添加一个元素
        inline void add(int x) {
            if (cnt[x]++ == 0) distinct++; 
        }

        // 删除一个元素
        inline void remove(int x) {
            if (--cnt[x] == 0) distinct--;
        }

        std::vector<int> run() {
            int m = qs.size();
            ans.assign(m, 0);

            std::sort(qs.begin(), qs.end(), [&](const Query& A, const Query& B) {
                int blockA = A.l / block;
                int blockB = B.l / block;
                if (blockA != blockB) return blockA < blockB;
                return (blockA & 1) ? (A.r < B.r) : (A.r > B.r); // 奇偶优化
            });

            int L = 1, R = 0; // 当前统计范围

            for (auto& q : qs) {
                while (L > q.l) add(a[--L]);
                while (R < q.r) add(a[++R]);
                while (L < q.l) remove(a[L++]);
                while (R > q.r) remove(a[R--]);

                ans[q.id] = distinct;
            }

            return ans;
        }
    };
}



// 数据结构库
namespace DS {

    // 朴素并查集
    class UnionFind {
    private:
        int n;                    // 元素数量
        std::vector<int> parent; // parent[i] = i 的父节点
        std::vector<int> size;   // size[i] = i 为根节点的集合大小

    public:
        // 构造：初始化 1~n
        UnionFind(int n) : n(n), parent(n + 1), size(n + 1, 1) {
            for (int i = 1; i <= n; ++i)
                parent[i] = i;
        }

        // 重置
        void reset() {
            for (int i = 1; i <= n; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // 找祖先（路径压缩）
        int find(int x) {
            assert(x >= 1 && x <= n);
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        // 判断是否同一集合
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 合并（按大小/秩优化）
        bool merge(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if (rx == ry) return false;

            // 小的挂大的（按 size 优化）
            if (size[rx] < size[ry])
                std::swap(rx, ry);

            parent[ry] = rx;
            size[rx] += size[ry];
            return true;
        }

        // 查询集合大小
        int getSize(int x) {
            return size[find(x)];
        }
    };

    // ST表 区间最值
    struct SparseTable {
        int n;                           // 元素数量
        int K;                           // 最大 log
        std::vector<int> log2v;               // 预处理 log2
        std::vector<std::vector<int>> st;          // ST 数组

        //   可自定义的区间合并函数（默认 max）
        static int mergeFunc(int a, int b) {
            return std::max(a, b);
        }

        //  构造函数：接收 vector<int>
        SparseTable(const std::vector<int> &arr) {
            build(arr);
        }

        //  构造函数：接收 C 数组
        SparseTable(int a[], int n) {
            std::vector<int> arr(a + 1, a + n + 1); // 下标 1-based
            build(arr);
        }

        //  预处理构建 ST 表
        void build(const std::vector<int> &arr) {
            n = arr.size() - 0;              // arr 必须从 0 或 1 开始都可以
            
            log2v.resize(n + 1);
            for (int i = 2; i <= n; ++i)
                log2v[i] = log2v[i / 2] + 1;
            
            K = log2v[n] + 1;
            st.assign(K, std::vector<int>(n + 1));

            // 0 次方：区间长度为 1
            for (int i = 1; i <= n; ++i)
                st[0][i] = arr[i - 1];   // 若 arr 是 1-based 自行改为 arr[i]

            // DP 构造 ST
            for (int k = 1; k < K; ++k) {
                for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
                    st[k][i] = mergeFunc(
                        st[k - 1][i],
                        st[k - 1][i + (1 << (k - 1))]
                    );
                }
            }
        }

        // 查询 [l, r] 区间最大值
        // O(1)
        int query(int l, int r) const {
            int k = log2v[r - l + 1];
            return mergeFunc(
                st[k][l],
                st[k][r - (1 << k) + 1]
            );
        }
    };

    // 树状数组 单点修改 区间求和
    class BIT {
    private:
        int n;
        std::vector<ll> tree;

        static int lowbit(int x) {
            return x & -x;
        }

    public:
        // 构造：给定大小 n，初始为 0
        BIT(int n) : n(n), tree(n + 1, 0) {}

        // 构造：从数组直接建树 O(n)
        BIT(const std::vector<ll> &a) : n(a.size()), tree(a.size() + 1, 0) {
            for (int i = 1; i <= n; ++i) {
                tree[i] += a[i - 1];
                int j = i + lowbit(i);
                if (j <= n) tree[j] += tree[i];
            }
        }

        // 单点增加：a[x] += v
        void add(int x, ll v) {
            assert(x >= 1 && x <= n);
            while (x <= n) {
                tree[x] += v;
                x += lowbit(x);
            }
        }

        // 单点修改：a[x] = v（需要先查当前值）
        void update(int x, ll v) {
            ll old = queryRange(x, x);
            add(x, v - old);
        }

        // 查询前缀和：sum(1..x)
        ll query(int x) const {
            assert(x >= 0 && x <= n);
            ll res = 0;
            while (x > 0) {
                res += tree[x];
                x -= lowbit(x);
            }
            return res;
        }

        // 查询区间和 [l, r]
        ll queryRange(int l, int r) const {
            assert(l <= r);
            return query(r) - query(l - 1);
        }
    };

    // 线段树 区间修改 区间求和
    class SegTree {
    private:
        struct Node {
            ll sum = 0;     // 区间和
            ll lazy = 0;    // lazy：整段区间需要加的值
        };

        int n;                     // 区间大小
        std::vector<Node> tr;           // 线段树（4n 空间）

        // PushUp: 更新父节点
        inline void pushup(int p) {
            tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum;
        }

        // PushDown: 下传 lazy
        inline void pushdown(int p, int l, int r) {
            ll tag = tr[p].lazy;
            if (tag == 0) return;

            int mid = (l+r) >> 1;

            // 左子
            tr[p<<1].lazy += tag;
            tr[p<<1].sum  += tag * (mid - l + 1);

            // 右子
            tr[p<<1|1].lazy += tag;
            tr[p<<1|1].sum  += tag * (r - mid);

            tr[p].lazy = 0;
        }

        // 建树：build(1,1,n)
        void build(int p, int l, int r, const std::vector<ll>& a) {
            if (l == r) {
                tr[p].sum = a[l];
                return;
            }
            int mid = (l+r)>>1;
            build(p<<1, l, mid, a);
            build(p<<1|1, mid+1, r, a);
            pushup(p);
        }

        // 区间加 update(1,1,n,L,R,val)
        void update(int p, int l, int r, int L, int R, ll val) {
            if (L <= l && r <= R) {
                tr[p].sum += val * (r - l + 1);
                tr[p].lazy += val;
                return;
            }
            pushdown(p, l, r);
            int mid = (l+r)>>1;
            if (L <= mid) update(p<<1, l, mid, L, R, val);
            if (R >  mid) update(p<<1|1, mid+1, r, L, R, val);
            pushup(p);
        }

        // 区间查询 query(1,1,n,L,R)
        ll query(int p, int l, int r, int L, int R) {
            if (L <= l && r <= R) return tr[p].sum;

            pushdown(p, l, r);
            int mid = (l+r)>>1;

            ll res = 0;
            if (L <= mid) res += query(p<<1, l, mid, L, R);
            if (R >  mid) res += query(p<<1|1, mid+1, r, L, R);
            return res;
        }

    public:

        // 仅指定大小，默认全 0
        SegTree(int n) : n(n) {
            tr.assign(4*n + 5, Node());
        }

        // 直接从数组构建（数组须下标从 1 开始）
        SegTree(const std::vector<ll>& a) {
            n = (int)a.size() - 1;  // 要求 a[1..n]
            tr.assign(4*n + 5, Node());
            build(1, 1, n, a);
        }

        // 对区间 [L,R] 每个元素 += val
        void rangeAdd(int L, int R, ll val) {
            update(1, 1, n, L, R, val);
        }

        // 查询区间 [L,R] 的和
        ll rangeQuery(int L, int R) {
            return query(1, 1, n, L, R);
        }
    };
}


// 字符串库
namespace SS {
    // 一维滚动Hash
    class StringHash1D {
    private:
        ull base;
        std::vector<ull> h, p;   // 前缀哈希、幂次数
        int n = 0;

    public:
        // 构造（默认 base = 131）
        StringHash1D(const string &s = "", ull base = 131) : base(base) {
            if (!s.empty()) init(s);
        }

        void init(const string &s) {
            n = s.size();
            h.assign(n + 1, 0);
            p.assign(n + 1, 0);
            p[0] = 1;

            for (int i = 1; i <= n; ++i) {
                h[i] = h[i - 1] * base + (unsigned char)s[i - 1];
                p[i] = p[i - 1] * base;
            }
        }

        // 查询区间 [l, r]（1-index）
        ull query(int l, int r) const {
            return h[r] - h[l - 1] * p[r - l + 1];
        }

        // 合并两个子串的哈希 (A followed by B)
        ull merge(ull h1, int len2, ull h2) const {
            return h1 * p[len2] + h2;
        }
    };

    // 二维滚动Hash
    class MatrixHash2D {
    private:    
        int n, m;
        ull base1, base2;
        std::vector<std::vector<ull>> h;      // h[i][j]
        std::vector<ull> p1, p2;         // base1^k, base2^k

    public:
        // 构造：传入矩阵与两种底数
        MatrixHash2D(const std::vector<std::vector<int>> &a,
                    ull base1 = 131, ull base2 = 233)
            : base1(base1), base2(base2)
        {
            init(a);
        }

        void init(const std::vector<std::vector<int>> &a) {
            n = a.size();
            m = a[0].size();

            h.assign(n + 1, std::vector<ull>(m + 1, 0));
            p1.assign(m + 1, 0);
            p2.assign(n + 1, 0);

            p1[0] = p2[0] = 1;
            for (int i = 1; i <= m; ++i) p1[i] = p1[i - 1] * base1;
            for (int i = 1; i <= n; ++i) p2[i] = p2[i - 1] * base2;

            // 行 → 列 两次前缀哈希
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    h[i][j] = h[i][j - 1] * base1 + a[i - 1][j - 1];

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    h[i][j] = h[i - 1][j] * base2 + h[i][j];
        }

        // 查询子矩阵 hash ([x1,y1] ~ [x2,y2]，1-index)
        ull query(int x1, int y1, int x2, int y2) const {
            ull A = h[x2][y2];
            ull B = h[x2][y1 - 1] * p1[y2 - y1 + 1];
            ull C = h[x1 - 1][y2] * p2[x2 - x1 + 1];
            ull D = h[x1 - 1][y1 - 1] * p1[y2 - y1 + 1] * p2[x2 - x1 + 1];
            return A - B - C + D;
        }
    };

    // 普通字典树
    class Trie {
    private:
        static const int A = 26;               // 字母表大小：小写英文
        std::vector<std::array<int, A>> ch;              // 儿子节点
        std::vector<int> cntEnd;                    // cntEnd[u]：以此节点结尾的单词数量
        std::vector<int> cntPass;                   // cntPass[u]：经过此节点的单词数量（用于前缀统计）

    public:
        Trie() {
            ch.push_back(std::array<int, A>{});     // root 节点 id = 0
            cntEnd.push_back(0);
            cntPass.push_back(0);
        }

        // 插入字符串
        void insert(const string &s) {
            int u = 0;
            for (char c : s) {
                int id = c - 'a';
                if (ch[u][id] == 0) {
                    ch[u][id] = ch.size();
                    ch.push_back(std::array<int, A>{});
                    cntEnd.push_back(0);
                    cntPass.push_back(0);
                }
                u = ch[u][id];
                cntPass[u]++;   // 经过 u
            }
            cntEnd[u]++;        // 在此结尾
        }

        // 是否存在完整字符串 s
        bool search(const string &s) const {
            int u = 0;
            for (char c : s) {
                int id = c - 'a';
                if (ch[u][id] == 0) return false;
                u = ch[u][id];
            }
            return cntEnd[u] > 0;
        }

        // 统计以 prefix 为前缀的字符串总数量（含重复字符串）
        int countPrefix(const string &prefix) const {
            int u = 0;
            for (char c : prefix) {
                int id = c - 'a';
                if (ch[u][id] == 0) return 0;
                u = ch[u][id];
            }
            return cntPass[u];
        }

        // DFS统计整个子树的单词数量（包含重复字符串）
        int countSubtree(int u) const {
            int ans = cntEnd[u];
            std::stack<int> st;
            st.push(u);

            while (!st.empty()) {
                int x = st.top(); st.pop();
                for (int i = 0; i < A; i++) {
                    int v = ch[x][i];
                    if (v) {
                        ans += cntEnd[v];
                        st.push(v);
                    }
                }
            }
            return ans;
        }
    };
}