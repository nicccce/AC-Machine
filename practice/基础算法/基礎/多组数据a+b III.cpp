#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        while (1)
        {
            int a, b;
            cin >> a >> b;
            if (a==0&&b==0) break;
            cout << a + b << "\n";
        }
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}