#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        getline(cin,s);
        int cnt=0;
        for(auto &c:s) {
            if(c!=' '&&c!='\n')   cnt++;
        }
        cout<<cnt<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}