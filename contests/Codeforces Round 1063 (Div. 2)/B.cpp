// https://codeforces.com/contests/2163/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)cin >> p[i];
        string x;
        cin >> x;
        if (x[0] == '1' || x[n-1] == '1') {
            cout << -1 << '\n';
            return;
        }
        int pos1 = -1,posn = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] == 1) pos1 = i;
            if (p[i] == n) posn = i;
        }
        bool bad = false;
        for (int i = 1; i < n-1; i++) {
            if (x[i] == '1' && (p[i] == 1 || p[i] == n)) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << -1 << '\n';
            return;
        }

        bool has_one = false;
        for (char c : x) {
            if (c == '1') {
                has_one = true;
                break;
            }
        }
        if (!has_one) {
            cout << 0 << '\n';
            return;
        }
        vector<pair<int, int>> ops;
        ops.push_back({1, n});
        int low = min(p[0], p[n-1]),high = max(p[0], p[n-1]);
        bool need_low = false;
        for (int i = 1; i < n-1; i++) {
            if (x[i] == '1' && p[i] < low) {
                need_low = true;
                break;
            }
        }
        bool need_high = false;
        for (int i = 1; i < n-1; i++) {
            if (x[i] == '1' && p[i] > high) {
                need_high = true;
                break;
            }
        }
        if (need_low) {
            int pos1_1 = pos1 + 1;
            ops.push_back({1, pos1_1});
            ops.push_back({pos1_1, n});
        }
        if (need_high) {
            int posn_1 = posn + 1;
            ops.push_back({1, posn_1});
            ops.push_back({posn_1, n});
        }
        cout << ops.size() << '\n';
        for (auto &op : ops) {
            cout << op.first << ' ' << op.second << '\n';
        }
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}