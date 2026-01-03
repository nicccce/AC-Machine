#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        string s;
        cin>>s;
        int cnt=0;
        for(char c:s) {
            cnt+=(c=='o');
        }
        cout<<cnt<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}