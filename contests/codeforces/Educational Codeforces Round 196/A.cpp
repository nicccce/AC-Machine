#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int l,r;
        cin>>l>>r;
        if(l>0||r<0)cout<<r-l<<'\n';
        else cout<<max(0ll,abs(l+r)-1)<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}