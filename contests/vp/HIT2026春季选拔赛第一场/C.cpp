#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<vector<int>> tree(n+1,vector<int>());
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<int> sum(n+1),dp(n+1);
        function<void(int,int)> dfs=[&](int now,int father){
            sum[now]=a[now];
            for(auto i:tree[now]){
                if(i==father)continue;
                dfs(i,now);
                // if(now==5){
                //     cout<<i<<' '<<sum[i]<<'\n';
                // }
                sum[now]+=sum[i];
            }
        };
        dfs(1,0);
        for(int i=2;i<=n;i++){
            dp[1]+=sum[i];
        }
        int ans=dp[1];
        function<void(int,int)> dfsdp=[&](int now,int father){
            dp[now]=dp[father];
            dp[now]+=sum[1]-2*sum[now];
            ans=max(dp[now],ans);
            for(auto i:tree[now]){
                if(i==father)continue;
                dfsdp(i,now);
            }
        };
        // cout<<sum[1]<<'\n';
        for(auto i:tree[1]){
            dfsdp(i,1);
        }
        cout<<ans<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}
