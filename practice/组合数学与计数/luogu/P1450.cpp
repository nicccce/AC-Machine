// https://www.luogu.com.cn/problem/P1450
// 容斥原理+完全背包预处理。先用完全背包处理无限制情况，再用容斥原理减去超过限制的方案数。
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e5+5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int c[5],n,dp[N][5];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=4;i++){
            cin>>c[i];
            dp[0][i]=1;
        }
        cin>>n;
        for(int i=1;i<N;i++){
            for(int j=1;j<=4;j++){
                dp[i][j]=dp[i][j-1]+((i>=c[j])?dp[i-c[j]][j]:0);
                // cout<<dp[i][j]<<' ';
            }
            // cout<<'\n';
        }
        auto getnum = [&](int i){
            if(i<0)return 0ll; 
            return dp[i][4];
        };
        for(int i=0;i<n;i++){
            int d[5],s;
            for(int i=1;i<=4;i++){
                cin>>d[i];
            }
            cin>>s;
            int ans=dp[s][4];
            for(int i=1;i<=4;i++){
                ans-=getnum(s-c[i]*(d[i]+1));
            }
            for(int i=1;i<=4;i++){
                for(int j=i+1;j<=4;j++){
                    ans+=getnum(s-c[i]*(d[i]+1)-c[j]*(d[j]+1));
                }
            }
            for(int i=1;i<=4;i++){
                int kk=0;
                for(int j=1;j<=4;j++){
                    kk+=(!(j==i))*c[j]*(d[j]+1);
                }
                ans-=getnum(s-kk);
            }
            {
                int kk=0;
                for(int j=1;j<=4;j++){
                    kk+=c[j]*(d[j]+1);
                }
                ans+=getnum(s-kk);
            }
            cout<<ans<<'\n';
        }
    };

    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}