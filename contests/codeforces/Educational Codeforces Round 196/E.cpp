#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn=6000,mod=998244353;
// 预处理 inv[i] = i^{-1} (mod mod)
// 要求 mod 为质数，且 0 <= n < mod
ll inv[maxn];
void getInverse(int n) {
    if (n == 0) return;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (mod - (ll)(mod / i) * inv[mod % i] % mod) % mod;
    }
}
// fac[i] = i!，ifac[i] = (i!)^{-1} (mod mod)
// 依赖上面的 getInverse，要求 mod 为质数，且 0 <= n < mod
ll fac[maxn], ifac[maxn];
void getFactorialInverse(int n) {
    getInverse(n);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
ll power(int a, int pls) {
    a %= mod;
    ll r = 1;
    while (pls) {
        if ((pls & 1))
            r = r * a % mod;
        a = (ll)a * a % mod;
        pls >>= 1;
    }
    return r;
}
int pls[maxn],f[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
        getFactorialInverse(maxn-1);
    pls[0]=1;
    for(int i=0;i<maxn-1;i++){
        int sum=0;
        for(int k=0;k<=i;k++) 
        sum=(sum+ifac[k]*ifac[i-k]%mod*pls[k])%mod;
        pls[i+1]=sum*fac[i]%mod;
    }
    f[0]=1,f[1]=0,f[2]=1,f[3]=1;
    for(int i=4;i<maxn;i++)
        f[i]=(f[i-2]+f[i-3])%mod;
    auto solve = [&]() {
        int n;
        string s;
        cin>>n>>s;
        int tot0=0,tot1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')tot0++;
            else tot1++;
        }
        int cnt=1,len=0,c0=0,c1=0,i=0;
        while(i<n){
            int j=i;
            while(j+1<n&&s[j]!=s[j+1])j++;
            int ll=j-i+1;
            if(ll>=2){
                len+=ll;
                int cntc=(ll+1)/2,cnto=ll/2;
                if(s[i]=='0'){
                    c0+=cntc,c1+=cnto;
                }else c1+=cntc,c0+=cnto;
                cnt=cnt*f[ll]%mod;
            }
            i=j+1;
        }
        int ans=n+len,anscnt=cnt*pls[tot0-c0]%mod*pls[tot1-c1]%mod;
        cout<<ans<<' '<<anscnt<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}