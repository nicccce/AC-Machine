#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            ans+=(n-i+1)*i;
        }
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}