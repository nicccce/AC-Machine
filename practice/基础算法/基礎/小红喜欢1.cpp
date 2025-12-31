#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        for(int i=1;i<=5;i++){
            int x;
            cin>>x;
            if(x==1){
                cout<<i;
                return;
            }
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}