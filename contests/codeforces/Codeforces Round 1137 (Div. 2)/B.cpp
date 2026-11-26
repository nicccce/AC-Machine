#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> tong(n+1);
        int cnt=0;
        for(int i=0;i<=n-k;i++){
            if(tong[a[i]]++==0)cnt++;
        }int ans=0;
        if(cnt==1)ans++;
        for(int i=1;i<k;i++){
            if(tong[a[i-1]]--==1)cnt--;
            if(tong[a[n-k+i]]++==0)cnt++;
            if(cnt==1)ans++;
        }cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}