#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word) {
            ans+=toupper(word[0]);
        }
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}