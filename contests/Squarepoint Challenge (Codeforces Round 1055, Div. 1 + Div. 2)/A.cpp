// https://codeforces.com/contest/2152/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        
        set<int> distinct;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            distinct.insert(x);
        }
        
        int m = distinct.size();
        cout << 2 * m - 1 << endl;
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}