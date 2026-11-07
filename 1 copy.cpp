#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int inf = LONG_LONG_MAX;
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,m,x,y,z;
        cin>>n>>m>>x>>y>>z;
        vector<int> a(n+1);
        vector<int> b(m+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        
        for(int i=1;i<=m;i++)cin>>b[i];
        vector<int> dp0(n+1),dp1(n+1);
        for(int i=1;i<=n;i++)dp0[i]=x+i*z;
        dp0[n]=0;
        for(int i=1;i<=m;i++){
            int mi=inf;
            dp1[1]=inf;
            for(int j=1;j<n;j++){
                mi=min(mi,dp0[j]+abs(a[(j+1)>n?1:(j+1)]-b[i])*y-j*z+(j==n)*x);
                dp1[(j+1)>n?1:(j+1)]=mi+(j)*z;
            }
            mi=inf;
            for(int j=n;j>=1;j--){
                mi=min(mi,dp0[j]+abs(a[(j+1)>n?1:(j+1)]-b[i])*y-j*z+x);
                dp1[j]=min(dp1[j],mi+(j-1+n)*z);
            }
            for(int j=1;j<=n;j++){
                dp0[j]=dp1[j];
            }
        }
        cout<<dp0[n]<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}