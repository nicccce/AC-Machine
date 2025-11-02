// https://ac.nowcoder.com/acm/contest/32708/K

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
        int n,a,b;
        cin>>n>>a>>b;
        if(a==0)cout<<1<<'\n';
        else if(n*a%b==0)cout<<n*a/b<<'\n';
        else if(n==1)cout<<1<<'\n';
        else {
            if(b*(n*a/b)>a*(n-1))cout<<n*a/b<<'\n';
            else cout<<n*a/b+1<<'\n';
        }
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}