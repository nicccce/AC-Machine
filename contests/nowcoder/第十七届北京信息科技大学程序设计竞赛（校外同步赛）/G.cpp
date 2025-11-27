// https://ac.nowcoder.com/acm/contest/122913/G
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if ((y1 - y2) * (x2 - x3) - (y2 - y3) * (x1 - x2)>0==(x1 - x2) * (x2 - x3) * (x1 - x3)>=0) {
            cout << "UP\n";
        } else {
            cout << "DOWN\n";
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}