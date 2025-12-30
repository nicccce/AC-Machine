#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<(a+b-c)*d;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}