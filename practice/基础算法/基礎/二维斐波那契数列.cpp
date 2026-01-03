#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m,1));
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
            }
        }
        cout<<a[n-1][m-1]<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}