#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int qpow(int b, int p){
    int r = 1;
    while (p){
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}
int inv(int x){
    return qpow(x, mod - 2);
}
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    vector<int> jc(200005);
    jc[1]=jc[0]=1;
    for(int i=2;i<200000;i++){
        jc[i]=jc[i-1]*i%mod;
    }
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<bool> a(n+1);
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            a[i]=(c=='1');
        }
        for(int i=1;i<=n;i++){
            if(!a[i]){
                cnt0++;
            }else if(i<n&&a[i+1]){
                cnt1++,i++;
            }
        }
        int ans=jc[cnt0+cnt1]*inv(jc[cnt1])%mod*inv(jc[cnt0])%mod;
        cout<<ans<<'\n';
        
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
