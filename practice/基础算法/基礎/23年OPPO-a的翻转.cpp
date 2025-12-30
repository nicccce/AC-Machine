#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        int ans=0;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++){
            ans+=((s[i]-'0')*pow(10,n-i-1))+((s[i]-'0')*pow(10,i));
        }
        cout<<ans<<endl;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}