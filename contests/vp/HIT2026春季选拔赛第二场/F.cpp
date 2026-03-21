#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
struct matrix{
    int m[2][2];
};
matrix operator * (const matrix& a, const matrix& b){
    matrix c;
    memset(c.m, 0, sizeof(c.m));

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]%mod)%mod;
    return c;
}

matrix qpow_matrix(matrix a, int n){
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));
    for(int i=0; i<2; i++) ans.m[i][i] = 1;
    while(n){
        if(n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve=[&](){
        int n,m;
        cin>>m>>n;
        vector<int> s(m),l(m);
        for(int i=0;i<m;i++)cin>>s[i];
        for(int i=0;i<m;i++)cin>>l[i];
        int l2=0,s2=0,ls=0,ssum=0,lsum=0;
        for(int i=0;i<m;i++){
            l2+=l[i]*l[i];
            s2+=s[i]*s[i];
            ls+=s[i]*l[i];
            ssum=(ssum+s[i])%mod;
            lsum=(lsum+l[i])%mod;
            l2%=mod;
            s2%=mod;
            ls%=mod;
        }
        matrix base{
            (s2+ls)%mod,s2,
            (ls+l2)%mod,ls
        };
        auto finmtr=qpow_matrix(base,n-1);
        int ans=((s[0]*finmtr.m[0][0]%mod+l[0]*finmtr.m[0][1]%mod)%mod*(ssum+lsum)%mod+(s[0]*(finmtr.m[1][0])%mod+l[0]*finmtr.m[1][1]%mod)%mod*ssum%mod)%mod;
        cout<<ans<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}