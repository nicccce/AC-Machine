#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int l,r;
        cin>>l>>r;
        for(int i=63;i>=0;i--){
            if((l&(1ll<<i))==(r&(1ll<<i))){
                l-=(l&(1ll<<i));
            }else{
                break;
            }
        }
        cout<<l<<"\n";
    };
    int t;
    for(cin>>t;t;t--)solve();
}