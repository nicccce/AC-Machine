#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> nums(n);
        nums[0]=0;nums[1]=1;nums[2]=1;
        for(int i=3;i<n;i++) nums[i]=nums[i-1]+2*nums[i-2]+nums[i-3];
        cout<<nums[n-1];

    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}