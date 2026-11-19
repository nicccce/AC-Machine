#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,maxn=2e5+10;
int qpow(int a, int b, int mod){
    a %= mod;
    int res = 1LL;
    while (b){
        if (b & 1LL)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return res % mod;
}
int inverse(int x, int mod) {
    return qpow(x, mod - 2, mod);
}
int inv[maxn];
void getInverse(int n) {
    if (n == 0) return;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    }
}
int fac[maxn], ifac[maxn];
void getFactorialInverse(int n) {
    getInverse(n);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
int C(int a,int b){
    if(b==0||b==a)return 1;
    return fac[a]*ifac[a-b]%mod*ifac[b]%mod;
}
int group[maxn];
inline int findroot(int x) {
    if (x == group[x])
        return x;
    return group[x] = findroot(group[x]);
}
inline void unite(int a, int b) {
    int ra = findroot(a);
    int rb = findroot(b);
    if (ra != rb)
        group[ra] = rb;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    getFactorialInverse(200005);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int> f(n+1),a(n+1),b(n+1);
        f[1]=0;
        for(int i=2;i<=n;i++){
            cin>>f[i];
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for (int i = 1; i <= n; i++)
            group[i] = i;
        vector<vector<int>> son(n+1);
        for(int i=1;i<=n;i++){
            son[f[i]].push_back(i);
        } 
        function<void(int)> dfs1=[&](int u){
            for(auto v:son[u]){
                if(a[u]<b[v]||b[u]<a[v])unite(v,u);
                dfs1(v);
            }
        };
        dfs1(1);
        vector<pair<int,int>> con;
        function<pair<int,int>(int)> dfs=[&](int u){
            vector<int> csize;
            int tans=1,sumsize=0;
            for(auto v:son[u]){
                if(findroot(v)==findroot(u)){
                    auto [cnt,sz]=dfs(v);
                    tans=tans*cnt%mod;
                    sumsize+=sz;
                    csize.push_back(sz);
                }else{
                    con.push_back(dfs(v));
                }
            }
            int tsumsize=sumsize+1;
            for(auto i:csize){
                tans=tans*C(sumsize,i)%mod;
                sumsize-=i;
            }
            return pair<int,int>{tans,tsumsize};
        };
        con.push_back(dfs(1));
        int ans=1;
        for(auto [cnt,sz]:con){
            // cout<<cnt<<' '<<sz<<'\n';
            ans=ans*cnt%mod*C(n,sz)%mod;
            n-=sz;
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
