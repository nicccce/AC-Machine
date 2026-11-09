#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=(n+n*(n-1)/2)%mod;
        array<int,3>dp[3]={};
        for(int i=2;i<=n;i++){
            dp[i%3]={0,0,0};
            for(int j=max(1LL,i-2);j<i;j++){
                int d=a[i]-a[j];
                if(d==1)
                    dp[i%3][0]=(1+dp[j%3][2])%mod,dp[i%3][1]=dp[j%3][0],
                    ans=(ans+dp[j%3][2]+dp[j%3][0])%mod;
                if(d==2)
                    dp[i%3][2]=(1+(dp[j%3][0]+dp[j%3][1])%mod)%mod,
                    ans=(ans+dp[i%3][2]+mod-1)%mod;
            }
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}