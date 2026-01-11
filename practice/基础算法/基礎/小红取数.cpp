#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x&1)ans++;
        }
        cout<<(ans==0?-1:ans)<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}