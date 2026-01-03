#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int mod=998244353;
    auto qpow = [&](int a,int b){
        int res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    };
    auto reverse = [&](int x){
        return qpow(x,mod-2);
    };
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> jc(n+1,1);
        for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<jc[i]*reverse(jc[j])%mod*reverse(jc[i-j])%mod<<" ";
            }
            cout<<"\n";
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}