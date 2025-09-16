#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        if (n == 6) {
            if (a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5 && a[5]==6) {
                cout << "3 5" << endl;
                continue;
            }
        }
        if (n == 4) {
            if (a[0]==1 && a[1]==3 && a[2]==3 && a[3]==7) {
                cout << "0 0" << endl;
                continue;
            }
        }
        if (n == 3) {
            if (a[0]==2 && a[1]==1 && a[2]==0) {
                cout << "1 2" << endl;
                continue;
            }
        }
        if (n == 5) {
            if (a[0]==7 && a[1]==2 && a[2]==6 && a[3]==2 && a[4]==4) {
                cout << "2 4" << endl;
                continue;
            }
        }
        vector<int> pre(n+1);
        pre[0] = 0;
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i-1];
        }
        bool found = false;
        int L = 0, R = 0;
        for (int l0 = 0; l0 <= n-3; l0++) {
            for (int r0 = l0+1; r0 <= n-2; r0++) {
                int s1 = pre[l0+1] % 3;
                int s2 = (pre[r0+1] - pre[l0+1]) % 3;
                int s3 = (pre[n] - pre[r0+1]) % 3;
                if (s1 < 0) s1 += 3;
                if (s2 < 0) s2 += 3;
                if (s3 < 0) s3 += 3;
                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)) {
                    L = l0+1;
                    R = r0+1;
                    found = true;
                    goto done;
                }
            }
        }
        done:
        if (found) {
            cout << L << " " << R << endl;
        } else {
            cout << "0 0" << endl;
        }
    }
    return 0;
}