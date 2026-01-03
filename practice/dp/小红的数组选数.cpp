#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&-x)
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto popcount = [&](int x){
        int res=0;
        while(x){
            res++;
            x-=lowbit(x);
        }
        return res;
    };
    auto solve = [&]() {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> dp(2000000,0);
        int ans=0;
        for(int i=1;i<(1<<n);i++) {
            int lbt=0;
            for(int j=0;j<n;j++) {
                if(i&(1<<j)) {
                    lbt=j;
                    break;
                }
            }
            if(popcount(i)==1){
                dp[i]=a[lbt];
            }
            else{
                if(dp[i^(1<<lbt)]>k){
                    dp[i]=k+1;
                    continue;
                }
                dp[i]=dp[i^(1<<lbt)]+a[lbt];
            }
            if(dp[i]==k)   ans++;
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}