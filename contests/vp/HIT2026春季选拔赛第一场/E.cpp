#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int>x(n);
        for(int&i:x)cin>>i;
        int l,q;cin>>l>>q;
        vector<vector<int>>dp(20,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[0][i]=upper_bound(x.begin(),x.end(),x[i]+l)-x.begin()-1;
        for(int k=1;k<20;k++){
            for(int i=0;i<n;i++)dp[k][i]=dp[k-1][dp[k-1][i]];
        }
        while(q--){
            int a,b;cin>>a>>b;
            if(a>b)swap(a,b);
            a--,b--;
            int ans=0;
            for(int k=19;k>=0;k--){
                if(dp[k][a]<b)a=dp[k][a],ans+=1<<k;
            }
            cout<<ans+1<<"\n";
        }
    };
    solve();
    return 0;
}