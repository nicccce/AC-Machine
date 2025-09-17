// https://www.luogu.com.cn/problem/P5520
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e5+5;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int t,m,n,p,ans=1;
        cin>>t>>n>>m>>p;
        for(int i=n-m+1;i>=n-2*m+2;i--)ans=(ans*i)%p;
        cout<<ans<<'\n';
    };

    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}