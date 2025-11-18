// https://codeforces.com/contest/2160/problem/D
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
        int total = 2 * n;
        vector<int> ans(total + 1, 0);
        vector<int> S;
        vector<int> B;

        for (int i = 1; i <= total; i++) {
            int k = S.size() + 1;
            vector<int> query_indices = S;
            query_indices.push_back(i);
            sort(query_indices.begin(), query_indices.end());

            cout << "? " << k;
            for (int idx : query_indices) {
                cout << " " << idx;
            }
            cout << endl;
            cout.flush();

            int x;
            cin >> x;

            if (x == 0) {
                S.push_back(i);
            } else {
                ans[i] = x;
            }
        }

        for (int i = 1; i <= total; i++) {
            if (ans[i] != 0) {
                B.push_back(i);
            }
        }
        sort(B.begin(), B.end());

        for (int i : S) {
            vector<int> query_indices = B;
            query_indices.push_back(i);
            sort(query_indices.begin(), query_indices.end());

            cout << "? " << query_indices.size();
            for (int idx : query_indices) {
                cout << " " << idx;
            }
            cout << endl;
            cout.flush();

            int x;
            cin >> x;
            ans[i] = x;
        }

        cout << "!";
        for (int i = 1; i <= total; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
        cout.flush();
};
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}