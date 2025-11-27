// https://ac.nowcoder.com/acm/contest/122913/L
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin >> n;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        vector<int> result(n);
        bool flip = false;
        
        for (int i = n; i >= 1; i--) {
            if (!flip) {
                result[i-1] = dq.front();
                dq.pop_front();
            } else {
                result[i-1] = dq.back();
                dq.pop_back();
            }
            flip = !flip;
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n-1) cout << " ";
        }
        cout << '\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}