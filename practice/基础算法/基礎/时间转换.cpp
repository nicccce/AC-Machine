#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int s,h,m;
        cin>>s;
        h=s/3600;
        m=s%3600/60;
        s=s%60;
        cout<<h<<' '<<m<<' '<<s;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}