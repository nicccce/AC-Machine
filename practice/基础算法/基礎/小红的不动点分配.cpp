#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=2*n;i++){
            int x;
            cin>>x;
            if(x<=n) a[x]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=min(a[i],2LL);
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}