// https://qoj.ac/contest/2644/problem/15298
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
vector<int> a, pre;

void solve() {
    cin >> n >> m >> k;
    a.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin() + 1, a.end());
    
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    
    int x = upper_bound(a.begin() + 1, a.end(), m) - a.begin();
    x--;
    
    int mi = 1e14;
    for (int y = 0; y <= k - x; y++) {
        int cnt = pre[x] * y + pre[k - y] * y - (pre[k] - pre[k - y]) * (n - k) + m * (n - x + y) * y;
        mi = min(mi, cnt);
    }

    int basic = 0;
    for (int i = 1; i <= k; i++) {
        basic += a[i] * (n - i + 1);
    }

    mi = min(mi + basic, basic);
    cout << mi << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}