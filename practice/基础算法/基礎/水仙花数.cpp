#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int m,n;
        while (cin>>m>>n){
        bool yes=false;
        for(int i=m;i<=n;i++){
            int sxh=0;
            for(auto c:to_string(i)){
                sxh+=pow(c-'0',3);
            }
            if(sxh==i) {    
                cout<<i<<' ';
                yes=true;
            }
        }
        if(!yes) cout<<"no";
        cout<<'\n';}
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}