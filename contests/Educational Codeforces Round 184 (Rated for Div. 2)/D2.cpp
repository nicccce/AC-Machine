// https://codeforces.com/contests/2163/problem/A
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
        int x, y, k;
        cin>>x>>y>>k;
        int L=1e12;
        for (int i = 0; i < x; i++) {
            if (L < y) break;
            L -= L / y;
        }
        if (L < k) {
            cout << "-1\n";
            return;
        }
        auto check = [&](int p){
            int kept = p;
            for (int i = 0; i < x; i++) {
                if (p < y) break;
                int take = p / y;
                kept -= take;
                p -= take;
            }
            return kept>=k;
        };
        int low = 1, high = 1e18;
        while (low < high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << '\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}
