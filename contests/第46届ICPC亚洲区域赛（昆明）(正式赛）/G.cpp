// https://ac.nowcoder.com/acm/contest/32708/G
#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]{
        int n;
        cin >> n;
        vector<double> a(n+1);
        for(int i=1; i<=n; i++) cin >> a[i];

        double ans = 0.0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n && j!=i; j++)
                ans += a[i]*a[j]/(a[i]+a[j]);
        ans *= 2.0;
        
        cout << setprecision(10) << ans << "\n";
    };

    solve();
    return 0;
}