#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        double x;
        cin>>x;
        if(x>=100&&x<500)cout<<x*0.9;
        else if(x>=500&&x<2000)cout<<x*0.8;
        else if(x>=2000&&x<5000)cout<<x*0.7;
        else if(x>=5000)cout<<x*0.6;
        else cout<<x;
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}