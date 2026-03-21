#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n,m,p=1e9+7;
        cin>>n>>m;
        int k=2*m,N=n+k-1;
        vector<vector<int>> f(N+1,vector<int>(k+1));
        for(int i=0;i<=N;i++){
            f[i][0]=1;
            for(int j=1;j<=min(i,k);j++)
                f[i][j]=(f[i-1][j-1]+f[i-1][j])%p;
        }
        cout<<f[N][k]<<'\n';
    };
    solve();
    return 0;
}