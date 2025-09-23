// https://codeforces.com/contest/1332/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e6+5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto qpow = [&](int x, int y) {
        int ans = 1;
        while (y) {
            if (y & 1) ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    };
    auto solve = [&]() {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        
        int total = n * m;
        if(total % 2 == 1) {
            cout << qpow((r - l + 1) % mod, total) << endl;
        } else {
            int E = (r / 2) - ((l - 1) / 2);
            int O = (r - l + 1) - E;
            int A = (O + E) % mod;
            int B = (O - E + mod) % mod;
            int term1 = qpow(A, total);
            int term2 = qpow(B, total);
            int inv2 = (mod + 1) / 2;
            int ans = (term1 + term2) % mod * inv2 % mod;
            cout << ans << endl;
        }
    };

    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}