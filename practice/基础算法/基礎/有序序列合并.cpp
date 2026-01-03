#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,m;
        vector<int> a;
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<m;i++) {
            int x;cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++) {
            cout<<a[i]<<" ";
        }   
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}