#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        double a,b;
        int c;
        cin>>a>>b>>c;
        if(abs(a-b-c) < 1e-6) cout<<"YES\n";
        else cout<<"NO\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}