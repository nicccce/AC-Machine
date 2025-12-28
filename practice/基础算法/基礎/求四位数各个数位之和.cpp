#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        char c;
        int ans=0;
        for(int i=0;i<4;i++){
            cin>>c;
            ans+=c-'0';
        }cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}