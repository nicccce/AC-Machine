#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int x =870699338-4,ans=0;
        for(int i=1;i*i<x;i++){
            if(x%i==0){
                ans+=i;
                ans+=x/i;
            }
        }
        if(((int)sqrt(x))*((int)sqrt(x))==x){
            ans+=((int)sqrt(x));
        }
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}