#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        cin>>s;
        int year=stoi(s.substr(0,4))+10;
        string ans=to_string(year)+s.substr(4,6);
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}