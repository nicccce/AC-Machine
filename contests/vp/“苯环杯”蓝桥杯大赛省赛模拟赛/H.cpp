#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int n;cin>>n;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++)cin>>p[i];
        vector<int> dp(n+1,2e18);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            vector<int> ndp(n+1,2e18);
            for(int j=0;j<i;j++){
                if(dp[j]==2e18)continue;
                ndp[j]=min(ndp[j],dp[j]+abs(p[i]-p[i-1]));
                ndp[i-1]=min(ndp[i-1],dp[j]+abs(p[i]-p[j]));
            }
            dp=ndp;
        }
        int ans=2e18;
        for(int i=0;i<n;i++)ans=min(ans,dp[i]);
        cout<<ans<<"\n";
    };
    int t;cin>>t;
    while(t--)solve();
    return 0;
}