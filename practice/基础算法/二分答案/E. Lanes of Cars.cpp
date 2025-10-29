// https://codeforces.com/contest/2120/problem/E
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a.begin(), a.end());
        auto check1 = [&](int mid) {
            int ct1 = 0, ct0 = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mid)ct1 += a[i] - mid;
                if (a[i] < mid - k)ct0 += mid - k - a[i];
            }
            return ct1 <= ct0;
        };
        int l = 1, r = 1e6;
        while (l < r) {
            int mid = l + r >> 1;
            if (check1(mid))r = mid;
            else l = mid + 1;
        }
        int res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > l) {
                res += (a[i] - l) * k;
                cnt += a[i] - l;
                a[i] = l;
            }
        }
        auto check2 = [&](int mid) {
            int ct = 0;
            for (int i = 0; i < n; i++) if (a[i] < mid)ct += mid - a[i];
            return ct <= cnt;
        };
        l = 1, r = 1e6;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check2(mid))l = mid;
            else r = mid - 1;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < l) cnt -= l - a[i],a[i] = l;
        }
        for (int i = 0; i < cnt; i++)a[i]++;
        multiset<int> se;
        for (int i = 0; i < n; i++) 
            se.insert(a[i]);
        while (true) {
            auto p1 = *se.begin(), p2 = *se.rbegin();
            if (p2 - p1 > k + 1) {
                se.erase(se.find(p1));
                se.erase(se.find(p2));
                se.insert(p1 + 1);
                se.insert(p2 - 1);
                res += k;
            } else break;
        }
        for (auto x: se) 
            res += x * (x + 1) / 2;
        cout << res << endl;
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}