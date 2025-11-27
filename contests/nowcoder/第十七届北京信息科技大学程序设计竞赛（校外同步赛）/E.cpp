// https://ac.nowcoder.com/acm/contest/122913/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int>jc(n+1,1);
        for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i;
        int dp0,dp1=1;
        for(int i=1;i<=n;i++){
            int tmp0=(dp0+dp1)%mod,tmp1=(dp1*2+dp0)%mod;
            dp0=tmp0,dp1=tmp1;
        }cout<<(dp0+dp1*2+mod-1)%mod;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}