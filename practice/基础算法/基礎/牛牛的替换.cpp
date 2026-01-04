#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        char a1,a2,a3,a4;
        cin>>n>>a1>>a2>>a3>>a4;
        string s;
        cin>>s;
        for(auto &c:s) {
            if(c==a1)   c=a2;
            if(c==a3)   c=a4;
        }
        cout<<s<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}