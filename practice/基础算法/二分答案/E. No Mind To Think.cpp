// https://codeforces.com/contest/2154/problem/E

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1), pre(n+1, 0);
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            ans += a[i];
        }

        sort(a.begin()+1, a.begin()+n+1);
        for(int i=1; i<=n; i++)
            pre[i] = pre[i-1]+a[i];

        for(int i=2; i<n; i++){  // 最后一个和第一个不可能是中位数

            function<int(int)> check = [&](int y){
                int L0 = min((y-1)*k, i-1);
                int L1 = min(y*k, i-1);
                int d =  (a[y+i]-a[i]-(a[i]*(L1-L0) - (pre[L1]-pre[L0])));
                return d;
            };

            int l=1LL, r=min(n-i,(i-1+k-1)/k);
            while(l <= r){
                int mid = (l+r)>>1LL;
                if(check(mid) <= 0){
                    l = mid+1;
                }
                else
                    r = mid-1;
            }
            int tmp = l-1;
            int L = min(tmp*k, i-1);
            ans = max(ans, pre[n] + a[i]*(tmp+L) - (pre[L]) - (pre[i+tmp]-pre[i]));
        }

        cout << ans << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}
