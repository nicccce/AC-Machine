// https://ac.nowcoder.com/acm/contest/122913/A
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a.begin(), a.end());
        cout<<a[n-2]*(n-1)<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}