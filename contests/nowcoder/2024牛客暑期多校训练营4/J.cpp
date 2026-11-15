#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=35,mod=998244353;
int C[maxn][maxn];
void init_comb(int maxn) {
    for (int i = 0; i <= maxn; ++i) {
        C[i][0] = 1; // 每一行的第 0 列都是 1
        for (int j = 1; j <= i; ++j) {
            // 如果需要取模：
            // C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            
            // 不取模（适用于 maxn <= 66）：
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        init_comb(maxn-1);
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> dp(k+1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                for(int j=0;j<=k;j++)dp[j]=0;
            }else if(s[i]=='1'){
                for(int j=k;j>=0;j--){
                    for(int x=0;x<j;x++){
                        dp[j]+=dp[x]*C[j][x]%mod;
                        dp[j]%=mod;
                    }
                    dp[j]++;
                }
                ans=(ans+dp[k])%mod;
            }else{
                for(int j=k;j>=0;j--){
                    for(int x=0;x<j;x++){
                        dp[j]+=dp[x]*C[j][x]%mod;
                        dp[j]%=mod;
                    }
                    dp[j]++;
                    dp[j]=dp[j]*499122177ll%mod;
                }
                ans=(ans+dp[k])%mod;
                
            }
            // cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}
