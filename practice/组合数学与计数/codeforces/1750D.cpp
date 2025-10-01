// https://codeforces.com/problemset/problem/1750/d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e6 + 5, mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto qpow = [&](int x, int y)
    {
        int ans = 1;
        while (y)
        {
            if (y & 1)
                ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    };
    auto getpri = [&](int n)
    {
        int d = 2;
        vector<int> a;
        while (d * d <= n)
        {
            bool este = false;
            while (n % d == 0)
            {
                n /= d;
                este = true;
            }
            if (este)
            {
                a.push_back(d);
            }
            d++;
        }
        if (n != 1)
        {
            a.push_back(n);
        }
        return a;
    };
    auto solve = [&]()
    {
        int n, m, ans = 1;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 2; i <= n; ++i)
            if (a[i - 1] % a[i] != 0)
            {
                cout << 0 << '\n';
                return;
            }
        vector<int> factori = getpri(a[1]);
        map<pair<int, int>, int> cal;
        for (int i = 2; i <= n; ++i)
        {
            cal[{a[i - 1], a[i]}] = 0;
        }
        for (auto i : cal)
        {
            int left = i.first.first / i.first.second;
            int till = m / i.first.second;
            vector<int> l;
            for (auto i : factori)
            {
                if (left % i == 0)
                {
                    l.push_back(i);
                }
            }
            int sz = (int)l.size();
            int ans = 0;
            for (int mask = 0; mask < (1ll << sz); ++mask)
            {
                int prod = 1;
                int cnt = 0;
                for (int j = 0; j < sz; ++j)
                {
                    if (mask & (1 << j))
                    {
                        prod *= l[j];
                        cnt++;
                    }
                }
                if (cnt % 2 == 0)
                {
                    ans += till / prod;
                }
                else
                {
                    ans -= till / prod;
                }
            }
            cal[i.first] = ans;
        }
        for (int i = 2; i <= n; ++i)
        {
            ans = ans * cal[{a[i - 1], a[i]}] % mod;
        }
        cout << ans << '\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}