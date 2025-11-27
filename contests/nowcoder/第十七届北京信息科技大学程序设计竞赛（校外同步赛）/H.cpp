// https://ac.nowcoder.com/acm/contest/122913/H
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
       int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        int dp0 = 0,dp1 = -0x3f3f3f3f3f;
        for (int i = 0; i < n; i++) {
            int tmp0 = max(dp0, dp1 - a[i]);
            int tmp1 = max(dp1, dp0 + a[i]);
            dp0 = tmp0;
            dp1 = tmp1;
        }
        cout << max(dp0, dp1) << '\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}