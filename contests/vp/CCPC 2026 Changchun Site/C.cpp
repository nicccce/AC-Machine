#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1),cnt(k+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<=k){
                a[i]=((a[i]-(i%k+1))%k+k)%k;
                // cout<<a[i]<<'\n';
                cnt[a[i]]++;
            }
        }int ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,cnt[i]);
        }
        cout<<n-ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)solve();
}