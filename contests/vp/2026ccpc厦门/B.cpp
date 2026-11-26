#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        int b=0,r=0;
        char lst='X';
        for(int i=0;i<n;i++){
            char now;cin>>now;
            if(now!=lst){
                if(now=='B')b++;
                if(now=='R')r++;
            }
            lst=now;
        }
        if(b>=r){
            cout<<"Red\n";
        }else{
            cout<<"Blue\n";
        }
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}