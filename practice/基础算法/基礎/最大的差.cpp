#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int mx=-1e18,mn=1e18;
        for(int i=0;i<n;i++) {
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        cout<<mx-mn;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}