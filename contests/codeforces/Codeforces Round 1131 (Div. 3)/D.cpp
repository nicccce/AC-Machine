#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int> a(n+1),prefix(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }sort(a.begin()+1,a.end(),greater());
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+a[i];
        }int ans=LONG_LONG_MAX;
        // for(int i=1;i<=n;i++){
        //     ans=min(ans,prefix[i]-a[i]*i+a[i]*(n-i)-(prefix[n]-prefix[i]));
        // }
        int i=(n+1)/2;
        cout<<prefix[i]-a[i]*i+a[i]*(n-i)-(prefix[n]-prefix[i])<<' '<<a[1]-a[n]<<'\n';
        
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}