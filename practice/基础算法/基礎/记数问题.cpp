#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,x;
        cin>>n>>x;
        int cntx=0;
        for(int i=1;i<=n;i++) {
            for(auto c:to_string(i)) {
                if(c-'0'==x) cntx++;
            }
        }
        cout<<cntx;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}