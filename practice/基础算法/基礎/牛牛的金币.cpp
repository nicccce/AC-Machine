#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int x,y,m,n;
        cin>>x>>y>>n>>m;
        if(n==x+1)cout<<'r';
        if(m==y+1)cout<<'u';
        if(n==x-1)cout<<'l';
        if(m==y-1)cout<<'d';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}