#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        for(int i=0;i<m;i++) {
            int l,r;
            char c1,c2;
            cin>>l>>r>>c1>>c2;
            for(int j=l-1;j<=r-1;j++) {
                if(s[j]==c1)   s[j]=c2;
            }
        }
        cout<<s<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}