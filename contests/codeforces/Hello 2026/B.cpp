// https://codeforces.com/contest/2183/problem/B
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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int nt=-1,ans=k-1;
        for (int i = 0; i < n; i++){
            if(a[i]-nt>1){
                ans=min(ans,nt+1);
                break;
            }nt=a[i];
        }ans=min(ans,nt+1);
        cout << ans << "\n";
    };
    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}