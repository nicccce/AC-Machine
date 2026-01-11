#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int b;
        cin>>b;
        int bb=sqrt(b);
        for(int i=-2;i<2;i++){
            if((bb-i)*(bb-i)==b){
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}