// https://codeforces.com/contest/2161/problem/A
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
        return ((int)x * (b / d) % n + n) % n;
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
        int n,X;
        cin >> n >> X;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int ts = accumulate(a.begin(), a.end(), 0LL);
        int K = ts / X;

        if (K == 0) {
            cout << 0 << "\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
            return;
        }

        vector<int> fi(a.begin(), a.end() - K);
        vector<int> ri(a.end() - K, a.end());

        sort(fi.begin(), fi.end(), greater<int>());
        sort(ri.begin(), ri.end());

        vector<int> order;
        int S = 0;
        int bonus = 0;
        int idx = 0;

        for (int p : ri) {
            while (idx < fi.size() && (S % X) + p < X) {
                S += fi[idx];
                order.push_back(fi[idx]);
                idx++;
            }
            S += p;
            order.push_back(p);
            bonus += p;
        }
        while (idx < fi.size()) {
            S += fi[idx];
            order.push_back(fi[idx]);
            idx++;
        }

        cout << bonus << "\n";
        for (int k = 0; k < order.size(); ++k) {
            cout << order[k] << (k == order.size() - 1 ? "" : " ");
        }
        cout << "\n";

    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}