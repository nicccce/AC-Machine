#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1;i<=n;++i) cin>>a[i];
        vector<int> l;
        int mxn = 0;
        for(int i=1;i<=n;++i) {
            if(a[i] > mxn) {
                l.pb(a[i]);
                mxn = a[i];
            }
        }
        vector<int> r;
        mxn = 0;
        for(int i=n;i>=1;--i) {
            if(a[i] > mxn) {
                r.pb(a[i]);
                mxn = a[i];
            }
        }

        int ml = l.size();
        vector<vector<int>> fl(n+1, vector<int>(ml+1));
        vector<vector<int>> gl(n+1, vector<int>(ml+1));
        fl[0][0] = 1;
        
        for(int i=1;i<=n;++i) {
            for(int j=0;j<=ml;++j) {
                fl[i][j] = (fl[i][j] + fl[i-1][j]) % mod;
                if(j && a[i] <= l[j-1]) {
                    fl[i][j] = (fl[i][j] + fl[i-1][j]) % mod;
                    gl[i][j] = (gl[i][j] + fl[i-1][j]) % mod;
                }
                if(j && a[i] == l[j-1]) {
                    fl[i][j] = (fl[i][j] + fl[i-1][j-1]) % mod;
                    gl[i][j] = (gl[i][j] + fl[i-1][j-1]) % mod;
                }
            }
        }

        int mr = r.size();
        vector<vector<int>> fr(n+2, vector<int>(mr+1));
        vector<vector<int>> gr(n+2, vector<int>(mr+1));
        fr[n+1][0] = 1;
        
        for(int i=n;i>=1;--i) {
            for(int j=0;j<=mr;++j) {
                fr[i][j] = (fr[i][j] + fr[i+1][j]) % mod;
                if(j && a[i] <= r[j-1]) {
                    fr[i][j] = (fr[i][j] + fr[i+1][j]) % mod;
                    gr[i][j] = (gr[i][j] + fr[i+1][j]) % mod;
                }
                if(j && a[i] == r[j-1]) {
                    fr[i][j] = (fr[i][j] + fr[i+1][j-1]) % mod;
                    gr[i][j] = (gr[i][j] + fr[i+1][j-1]) % mod;
                }
            }
        }

        int ans = 0;
        int mx = *max_element(a.begin()+1, a.end());
        
        for(int i=1;i<=n;++i) {
            if(a[i] == mx) {
                ans = (ans + gl[i][ml] * (fr[i+1][mr] + fr[i+1][mr-1])) % mod;
                for(int j=i+1;j<=n;++j) {
                    if(a[j] == mx) {
                        ans = (ans + fl[j][ml-1] * gr[j][mr]) % mod;
                    }
                }
                break;
            }
        }
        
        cout << ans << "\n";
    };

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}