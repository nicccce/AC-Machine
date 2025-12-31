#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            if(i%4&&string(to_string(i)).find("4")==string::npos) cout<<i<<'\n';
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}