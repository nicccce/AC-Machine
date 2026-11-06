#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,ans=0;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++)if(a[j]%a[i]==0)cnt++;
            ans=max(ans,cnt);
        }
        cout<<n-ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}