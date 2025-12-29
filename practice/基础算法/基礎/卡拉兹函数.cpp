#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        if(n%2==0)cout<<n/2;
        else cout<<3*n+1;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}