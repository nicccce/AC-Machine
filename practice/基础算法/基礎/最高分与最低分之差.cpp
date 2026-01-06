#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,x,mi=200,mx=0;
        cin>>n;
        while (n--)
        {
            cin>>x;
            mi=min(mi,x);
            mx=max(mx,x);
        }cout<<mx-mi;
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}