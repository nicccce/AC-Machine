#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int cur_cost = 0;
    vector<pair<int, int>> events;
    int mx = -4e18; // 记录前 i-1 轮的 max(a[j] + b[j])

    for (int i = 0; i < n; i++) {
        int L = (i == 0) ? 0LL : max(0LL, mx - a[i]);
        int R = b[i];
        if (L < R) {
            cur_cost += (R - L) * y; // A = 0 时第 i 轮需要购买的镀层代价
            events.push_back({L, 1});
            events.push_back({R, -1});
        }
        mx = max(mx, a[i] + b[i]);
    }

    sort(events.begin(), events.end());

    int ans = cur_cost;
    int active = 0, prev_A = 0;

    for (auto& [curr_A, delta] : events) {
        // 从 prev_A 推进到 curr_A，每增加 1 点 A，代价变化为 x - active * y
        cur_cost += (curr_A - prev_A) * (x - active * y);
        ans = min(ans, cur_cost);
        active += delta;
        prev_A = curr_A;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}