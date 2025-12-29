#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int x,l,r;
        cin>>x>>l>>r;
        if(l<=x and x<=r) cout<<"true\n";
        else cout<<"false\n";  
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}