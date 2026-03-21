#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n,m,p=1e9+7;
        cin>>n>>m;
        int k=2*m,nn=n+k-1;
        vector<int> jc(nn+1),v(nn+1);
        jc[0]=1;
        for(int i=1;i<=nn;i++)
            jc[i]=jc[i-1]*i%p;
        auto qppow=[&](int a,int b){
            int r=1;
            while(b){
                if(b&1)r=r*a%p;
                a=a*a%p;
                b>>=1;
            }
            return r;
        };
        v[nn]=qppow(jc[nn],p-2);
        for(int i=nn-1;i>=0;i--)v[i]=v[i+1]*(i+1)%p;
        cout<<jc[nn]*v[k]%p*v[nn-k]%p<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}