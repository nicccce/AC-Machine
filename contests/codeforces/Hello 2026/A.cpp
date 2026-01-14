// https://codeforces.com/contest/2183/problem/A
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if(a[0]==1 || a[n-1]==1){
            cout << "Alice\n";
            return;
        }else{
            cout << "Bob\n";
            return;
        }
    };
    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}