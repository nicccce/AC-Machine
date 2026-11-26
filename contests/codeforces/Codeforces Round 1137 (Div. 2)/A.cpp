#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int x;cin>>x;
        if(x%4!=0||x%2==1){
            cout<<"YES\n";
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}