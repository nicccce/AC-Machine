// https://www.luogu.com.cn/problem/P4071
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e6+5,mod=1e9+7;
int frac[N]={1,1,2},d[N]={1,0,1};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=3;i<N-2;i++){
        frac[i]=frac[i-1]*i%mod;
        d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
    }
    auto qpow = [&](int x, int y) {
        int ans = 1;
        while (y) {
            if (y & 1) ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    };
    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        cout<<d[n-m]*frac[n]%mod*qpow(frac[n-m],mod-2)%mod*qpow(frac[m],mod-2)%mod<<'\n';
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}