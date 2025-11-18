// https://codeforces.com/contests/2163/problem/A
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
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)cin >> a[i];
        sort(a.begin(), a.end());
        for(int i=1;i<n-1;i+=2)
            if(a[i]!=a[i+1]){
                cout<<"NO\n";
                return;
            }
        cout << "YES\n";
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}