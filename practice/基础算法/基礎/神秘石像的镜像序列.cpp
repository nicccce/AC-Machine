#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        vector<int> nums;
        int x;
        while (1)
        {
            cin>>x;
            if(x==0) break;
            nums.push_back(x);
        }
        for(int i=(int)nums.size()-1;i>=0;i--) cout<<nums[i]<<" ";

    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}