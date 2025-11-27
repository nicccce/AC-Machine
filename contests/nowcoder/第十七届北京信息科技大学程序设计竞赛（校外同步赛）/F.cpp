// https://ac.nowcoder.com/acm/contest/122913/F
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
        printf("%.6lf",(3.0 * n - 2.0) / (2.0 * (2.0 * n - 1.0)));
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}