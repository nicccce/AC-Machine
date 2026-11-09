#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pre(n, 0), suf(n, 0);
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], abs(a[i] - a[i - 1]));
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], abs(a[i + 1] - a[i]));
    }

    int mx = pre[n - 1];
    if (mx == 0) {
        cout << 0 << '\n';
        return;
    }

    vector<int> pos;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i] - a[i + 1]) == mx) pos.push_back(i);
    }

    if (pos.size() >= 3) {
        cout << mx << '\n';
        return;
    }

    int ans = mx;

    if (pos.size() == 2) {
        int l = pos[0] + 1, r = pos[1];
        int cur = max(pre[l - 1], suf[r + 1]);
        cur = max(cur, abs(a[l - 1] - 2 * a[r]));
        cur = max(cur, abs(a[r + 1] - 2 * a[l]));
        for (int i = l; i < r; i++) {
            cur = max(cur, 2 * abs(a[i + 1] - a[i]));
        }
        ans = min(ans, cur);
        cout << ans << '\n';
        return;
    }

    int idx = pos[0];

    int internal_mx = 0;
    for (int l = idx; l >= 0; l--) {
        if (l < idx) internal_mx = max(internal_mx, 2 * abs(a[l + 1] - a[l]));
        int cur = max(internal_mx, suf[idx + 1]);
        if (l > 0) {
            cur = max(cur, pre[l - 1]);
            cur = max(cur, abs(a[l - 1] - 2 * a[idx]));
        }
        cur = max(cur, abs(a[idx + 1] - 2 * a[l]));
        ans = min(ans, cur);
    }

    internal_mx = 0;
    for (int r = idx + 1; r < n; r++) {
        if (r > idx + 1) internal_mx = max(internal_mx, 2 * abs(a[r] - a[r - 1]));
        int cur = max(internal_mx, pre[idx]);
        if (r + 1 < n) {
            cur = max(cur, suf[r + 1]);
            cur = max(cur, abs(a[r + 1] - 2 * a[idx + 1]));
        }
        cur = max(cur, abs(a[idx] - 2 * a[r]));
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}