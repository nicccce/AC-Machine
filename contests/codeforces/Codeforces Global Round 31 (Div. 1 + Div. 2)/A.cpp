#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int l,a,b;
        cin>>l>>a>>b;
        cout<<((l-a-1)/(__gcd(l,b))*__gcd(l,b)+a)%l<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}