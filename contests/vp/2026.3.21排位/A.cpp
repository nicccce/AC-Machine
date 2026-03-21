#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<bool>> a(n+2,vector<bool>(m+2));
        auto check=[&](int i,int j){
            return a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1];
        };
        for(int x=1;x<=k;x++){
            int i,j;
            cin>>i>>j;
            a[i][j]=1;
            if(check(i,j)||check(i-1,j-1)||check(i-1,j)||check(i,j-1)){
                cout<<x<<"\n";
                return;
            }
        }
        cout<<0;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}