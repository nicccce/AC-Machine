// https://ac.nowcoder.com/acm/contest/122913/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto qpow = [&](int b, int p){
        int r = 1;
        while (p){
            if (p & 1)
                r = r * b % mod;
            b = b * b % mod, p >>= 1;
        }
        return r;
    };
    auto solve = [&]() {
        int n;
        cin>>n;
        cout<<qpow(2,n-1)<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}