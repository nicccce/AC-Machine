#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        if(n%400==0||(n%4==0&&n%100!=0))cout<<"yes\n";
        else cout<<"no\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}