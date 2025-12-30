#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> fbnq(n);
        fbnq[0]=1;
        fbnq[1]=1;
        for(int i=2;i<n;i++){
            fbnq[i]=fbnq[i-1]+fbnq[i-2];
        }
        cout<<fbnq[n-1]<<endl;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}