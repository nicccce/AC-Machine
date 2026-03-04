#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> r1(n+1),r2(n+1);
        for(int i=1;i<=n;i++)cin>>r1[i],r1[i]+=r1[i-1];
        for(int i=1;i<=n;i++)cin>>r2[i],r2[i]+=r2[i-1];
        int ans=LLONG_MAX;
        for(int i=1;i<=n;i++){
            ans=min(ans,max(r1[n]-r1[i],r2[i-1]));
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
