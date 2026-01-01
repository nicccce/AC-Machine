#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        set<int> s;
        for(int i=0;i<n;i++) {cin>>a[i];
            if(s.count(a[i])) continue;
            cout<<a[i]<<" ";
            s.insert(a[i]);}
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}