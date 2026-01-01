#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        vector<int> nums(10);
        for(int i=0;i<10;i++) cin>>nums[i];
        for(int i=9;i>=0;i--) cout<<nums[i]<<" ";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}