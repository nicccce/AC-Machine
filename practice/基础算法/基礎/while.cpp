#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s,ss="while";
        int cnt;
        cin>>s;
        cnt=0;
        for(int i=0;i<5;i++) {
            if(s[i]!=ss[i])   cnt++;
        }
        cout<<cnt<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}