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
        for(int i=0;i<n;i++) cin>>a[i];
        int x,cnt=0;
        cin>>x;
        for(int i=0;i<n;i++) {
            if(a[i]==x) cnt++;
        }
        cout<<cnt;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}