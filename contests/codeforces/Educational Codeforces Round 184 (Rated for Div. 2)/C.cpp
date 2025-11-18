// https://codeforces.com/contest/2169/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1),p(n+1);
        int ans=0,mn=0,summ=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            summ+=a[i];
            p[i]=p[i-1]+i*i+i-(i-1)*(i-1)-(i-1)-a[i];
            ans=max(ans,p[i]-mn);
            mn=min(p[i],mn);
        }
        cout<<summ+ans<<'\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}