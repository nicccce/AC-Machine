#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<2*(a*b+b*c+a*c)<<'\n'<<a*b*c;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}