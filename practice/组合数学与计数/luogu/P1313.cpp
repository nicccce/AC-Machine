// https://www.luogu.com.cn/problem/P1313
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e6+5,mod=10007;
int frac[N]={1};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<N-2;i++){
        frac[i]=frac[i-1]*i%mod;
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
        int a,b,k,n,m;
        cin>>a>>b>>k>>n>>m;
        if(n+m!=k){cout<<0;return;}
        cout<<frac[k]*qpow(frac[k-n],mod-2)%mod*qpow(frac[n],mod-2)%mod*qpow(a,n)%mod*qpow(b,m)%mod;
    };

    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}