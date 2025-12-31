#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        int summ=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int x;
                cin>>x;
                if(x>0) summ+=x;
            }
        }
        cout<<summ;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}