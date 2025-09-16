#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        vector<int> b(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int dp[2][1005]={0};
        dp[1][1]=dp[0][1]=1;
        for(int i=2;i<=n;i++){
            dp[0][i]=(dp[0][i] + (a[i]>=a[i-1]&&b[i]>=b[i-1])*dp[0][i-1]+(a[i]>=b[i-1]&&b[i]>=a[i-1])*dp[1][i-1])%mod;
            dp[1][i]=(dp[1][i] + (a[i]>=a[i-1]&&b[i]>=b[i-1])*dp[1][i-1]+(a[i]>=b[i-1]&&b[i]>=a[i-1])*dp[0][i-1])%mod;
        }
        cout<<(dp[0][n]+dp[1][n])%mod<<'\n';
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}