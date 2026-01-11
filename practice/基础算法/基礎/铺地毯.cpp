#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<tuple<int,int,int,int>> carpets(n+1);
        for(int i=1;i<=n;i++){
            int a,b,g,k;
            cin>>a>>b>>g>>k;
            carpets[i] = make_tuple(a,b,g,k);
        }
        int x,y;
        cin>>x>>y;
        int ans = -1;
        for(int i=1;i<=n;i++){
            auto [a,b,g,k] = carpets[i];
            if(x>=a && x<=a+g && y>=b && y<=b+k){
                ans = i;
            }
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}