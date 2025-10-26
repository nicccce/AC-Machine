#include<bits/stdc++.h>
using namespace std;
#define int long long

struct sb {
    int w, v;
    friend bool operator<(sb x, sb y) {
        return x.v > y.v;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n, W, k;
        cin >> n >> W >> k;

        vector<sb> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i].w >> a[i].v;
        sort(a.begin(), a.end());

        // for(int i = 0; i < n; i++) 
        //     cout << a[i].w << " " << a[i].v << "\n";
        
        int sum = 0;
        for(int i = 0; i < k; i++) sum += a[i].v;
        
        vector< array<int, 2> > dp(W + 1);
        for(int i = 0; i <= W; i++) 
            dp[i][0] = sum, dp[i][1] = k;

        // for(int j = 0; j <= W; j++) cout << dp[j][0] << " "; cout << "\n";
        
        for(int i = 0; i < n; i++) {
            for(int j = W; j >= a[i].w; j--) {
                if(i < dp[j - a[i].w][1]) {
                    if(dp[j - a[i].w][0] + a[dp[j - a[i].w][1]].v > dp[j][0]) {
                        dp[j][0] = dp[j - a[i].w][0] + a[dp[j - a[i].w][1]].v;
                        dp[j][1] = dp[j - a[i].w][1] + 1;
                    } 
                    else if(dp[j - a[i].w][0] + a[dp[j - a[i].w][1]].v == dp[j][0]) {
                        dp[j][1] = min(dp[j][1], dp[j - a[i].w][1] + 1);
                    }
                }
                else {
                    if(dp[j - a[i].w][0] + a[i].v > dp[j][0]) {
                        dp[j][0] = dp[j - a[i].w][0] + a[i].v;
                        dp[j][1] = dp[j - a[i].w][1];
                    }
                    else if(dp[j - a[i].w][0] + a[i].v == dp[j][0]) {
                        dp[j][1] = min(dp[j][1], dp[j - a[i].w][1]);
                    }
                }
            }

            // for(int j = 0; j <= W; j++) cout << dp[j][0] << " "; cout << "\n";
        }

        int ans = 0;
        for(int i = W; i >= 0; i--)
            ans = max(ans, dp[i][0]);
        cout << ans << "\n";
    };

    solve();
    return 0;
}