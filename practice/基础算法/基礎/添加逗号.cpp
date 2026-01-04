#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        string s=to_string(n);
        reverse(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.size();i++) {
            if(i&&i%3==0)   ans+=',';
            ans+=s[i];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}