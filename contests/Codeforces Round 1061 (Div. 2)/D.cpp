//  https://codeforces.com/contest/2156/problem/D
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
        int n,k;
        cin>>n>>k;
        vector<int> a(n),cnt(6*n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(),a.end());
        int ans = 1;
        for(int i=1;i<=n;i++){
            int c = upper_bound(a.begin(),a.end(),i*4)-a.begin();
            if(c-cnt[i]-cnt[2*i]-cnt[3*i]-cnt[4*i]<=k)ans = max(ans,i);
        }
        cout<<ans<<'\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}