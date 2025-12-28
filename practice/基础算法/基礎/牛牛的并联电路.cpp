#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        double r1,r2;cin>>r1>>r2;
        cout<<(r1*r2)/(r1+r2);
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}