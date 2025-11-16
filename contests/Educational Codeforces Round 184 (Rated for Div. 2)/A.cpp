// https://codeforces.com/contest/2169/problem/A
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
        int n,b;
        cin>>n>>b;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        int x=a.end()-upper_bound(a.begin(),a.end(),b),y=lower_bound(a.begin(),a.end(),b)-a.begin()+1;
        if(y>x){
            cout<<b-1<<'\n';
        }else{
            cout<<b+1<<'\n';
        }

    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}