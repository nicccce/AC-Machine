#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,a,b,c,cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            if(a+b+c<180)cnt++;
        }
        cout<<cnt<<endl;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}