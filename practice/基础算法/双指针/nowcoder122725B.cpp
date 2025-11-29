// https://ac.nowcoder.com/acm/contest/122725/B
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        int ans,a;
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a>>b[i];
            ans+=a;
        }
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<n;i++){
            ans-=b[i]*i;
        }
        cout<<ans<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}