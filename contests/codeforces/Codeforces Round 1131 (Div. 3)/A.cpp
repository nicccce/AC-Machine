#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,m;cin>>n>>m;
        string p,q;cin>>p>>q;
        vector<int> cnt(200);
        for(char i:p)cnt[i]++;
        for(char i:q)cnt[i]--;
        for(int i=1;i<200;i++){
            if(i=='s'||i=='i'||i=='x'){
                if(cnt[i]!=1){
                    cout<<"NO\n";
                    return;
                }
            }else{
                if(cnt[i]!=0){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        cout<<"YES\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}