// https://ac.nowcoder.com/acm/contest/122913/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        if(n%2+m%2==0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}