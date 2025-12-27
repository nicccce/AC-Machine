#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        // int m,n;
        // cin>>m>>n;
        // printf("%f",1.0*m/n);
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        cout<<s;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}