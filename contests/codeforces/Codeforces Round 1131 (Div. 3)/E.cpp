#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    auto solve = [&]() {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b[i] = (i % 2 == 0 ? x : -x);
        }
        sort(b.begin(), b.end());
        int ans = 0;
        int neg_cnt = n / 2;
        for (int i = 0; i < n; i++) {
            if (i < neg_cnt) ans -= b[i];
            else ans += b[i];
        }
        cout << ans << '\n';
    };
    int t;
    for (cin >> t; t; t--) solve();
    return 0;
}