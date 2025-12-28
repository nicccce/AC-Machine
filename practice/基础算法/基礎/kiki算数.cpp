#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b;
        cin>>a>>b;
        cout<<(a+b)%100;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}