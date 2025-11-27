// https://ac.nowcoder.com/acm/contest/122913/M
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        double x;
        cin >> x;
        printf("%.2f",x<60?0.00:1.0+(x-60)*0.1);
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}