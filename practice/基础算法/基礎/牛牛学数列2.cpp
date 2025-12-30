#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        double ans=0;
        for(int i=1;i<=n;i++){
            ans+=1.0/i;
        }
        cout<<ans<<endl;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}