//  https://codeforces.com/contest/2156/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
class _Math
{
public:
    static int qpow(int b, int p)
    {
        int r = 1;
        while (p)
        {
            if (p & 1)
                r = r * b % mod;
            b = b * b % mod, p >>= 1;
        }
        return r;
    }
    static int inv(int x)
    {
        return qpow(x, mod - 2);
    }
    vector<int> pri;
    vector<int> phi;
    void Prime_pre(int n)
    {
        phi = vector<int>(n + 1);
        vector<bool> not_prime(n + 1, 0);
        phi[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!not_prime[i])
            {
                pri.push_back(i);
                phi[i] = i - 1;
            }
            for (int pri_j : pri)
            {
                if (i * pri_j > n)
                    break;
                not_prime[i * pri_j] = true;
                if (i % pri_j == 0)
                {
                    phi[i * pri_j] = phi[i] * pri_j;
                    break;
                }
                phi[i * pri_j] = phi[i] * phi[pri_j];
            }
        }
    }
    int ex_gcd(int a, int b, int &x, int &y)
    {
        if (!b)
        {
            x = 1;
            y = 0;
            return a;
        }
        else
        {
            int d = ex_gcd(b, a % b, y, x);
            y -= a / b * x;
            return d;
        }
    }

    int solve_linear_congruence_equation(int a, int b, int n)
    {
        int x, y;
        int d = ex_gcd(a, n, x, y);
        if (b % d)
            return -1;
        n /= d;
        return ((long long)x * (b / d) % n + n) % n;
    }
    // int log_2(int x)
    // {
    //     return __bit_width(x) - 1;
    // }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& i : arr) cin >> i;

        auto check = [&](int goal) {
            vector<vector<int>> f(n);
            vector<int> cnt(3, 0);
            vector<array<int, 2>> minn(3, {-1, 0x3f3f3f3f});
            for (int i = 0; i < n; ++i)
                for (int j = 2; j >= 0; --j) {
                    auto& [idx, val] = minn[j];
                    if (idx != -1 && arr[i] - arr[idx] >= goal) {
                        f[idx].push_back(i);
                        f[i].push_back(idx);
                    }
                    if (val > arr[i]) {
                        minn[min<int>(2, j + 1)] = minn[j];
                        idx = i, val = arr[i];
                    }
                }

            int ok3 = 0, ok2 = 0;
            vector<char> check(n, 0);
            for (int i = 0; i < n; ++i) {
                if (f[i].size() == 2) check[i] = true, ++ok2;
                if (f[i].size() > 2) ++ok3;
            }
            if (ok3 > 1) return true;

            for (int i = 0; i < n; ++i) {
                int cnt2 = f[i].size() == 2, cnt3 = f[i].size() > 2;
                for (auto j : f[i]) cnt2 += check[j];
                if (cnt3 == ok3 && cnt2 == ok2) return false;
            }
            return true;
        };

        int l = -2e9, r = 2e9, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << '\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}