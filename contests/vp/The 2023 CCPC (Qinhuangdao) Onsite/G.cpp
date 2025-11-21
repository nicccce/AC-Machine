// https://codeforces.com/gym/104787/problem/G
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        int ans = 0;
        for(int i = 1; i < n; i++) ans += abs(a[i] - a[i - 1]);
        for(int i = 1; i < m; i++) ans += abs(b[i] - b[i - 1]);

        cout << ans << "\n";


    };

    solve();

    return 0;
}